import numpy as np
from tensorflow import keras
from keras.datasets import mnist
# from keras.utils import np_utils
from tensorflow.keras.utils import to_categorical
from keras.models import Sequential
from keras.layers import Conv2D, MaxPooling2D, Flatten, Dense
from keras.callbacks import TensorBoard
from tensorflow.keras.preprocessing.image import ImageDataGenerator
from keras.layers import Dense, Dropout, Flatten

# 加载MNIST数据集
(X_train, Y_train), (X_test, Y_test) = mnist.load_data()

# 预处理数据
X_train = X_train.reshape(-1, 28, 28, 1).astype('float32') / 255.0
X_test = X_test.reshape(-1, 28, 28, 1).astype('float32') / 255.0
# Y_train = np_utils.to_categorical(Y_train, 10)
# Y_test = np_utils.to_categorical(Y_test, 10)
Y_train = to_categorical(Y_train, 10)
Y_test = to_categorical(Y_test, 10)


def build_lenet():
    model = Sequential()
    model.add(Conv2D(6, (5, 5), activation='relu', input_shape=(28, 28, 1)))
    model.add(MaxPooling2D(pool_size=(2, 2)))
    model.add(Conv2D(16, (5, 5), activation='relu'))
    model.add(MaxPooling2D(pool_size=(2, 2)))
    model.add(Flatten())
    model.add(Dense(120, activation='relu'))
    model.add(Dense(84, activation='relu'))
    model.add(Dense(10, activation='softmax'))
    return model

lenet_model = build_lenet()
lenet_model.compile(loss='categorical_crossentropy', optimizer='adam', metrics=['accuracy'])

lenet_model.fit(X_train, Y_train, epochs=10, batch_size=32, validation_split=0.2)

loss_and_metrics = lenet_model.evaluate(X_test, Y_test, batch_size=32)
print('LeNet loss and accuracy:', loss_and_metrics)

# 设置数据增强的参数
datagen = ImageDataGenerator(
    rotation_range=10,
    width_shift_range=0.1,
    height_shift_range=0.1,
    shear_range=0.1,
    zoom_range=0.1,
    horizontal_flip=False,
    fill_mode='nearest'
)

# 拟合数据增强器到训练数据
datagen.fit(X_train)

# 使用数据增强器生成的新数据训练模型
lenet_model.fit(datagen.flow(X_train, Y_train, batch_size=32), epochs=10, validation_data=(X_test, Y_test))

# 设置TensorBoard日志文件的保存路径
tensorboard_callback = TensorBoard(log_dir='./logs', histogram_freq=1, write_graph=True)

# 使用TensorBoard回调函数进行模型训练
lenet_model.fit(datagen.flow(X_train, Y_train, batch_size=32), epochs=10, validation_data=(X_test, Y_test), callbacks=[tensorboard_callback])

# 定义全连接BP网络模型
def build_bp_network():
    model = Sequential()
    model.add(Flatten(input_shape=(28, 28, 1)))
    model.add(Dense(512, activation='relu'))
    model.add(Dropout(0.2))
    model.add(Dense(512, activation='relu'))
    model.add(Dropout(0.2))
    model.add(Dense(10, activation='softmax'))
    return model

# 编译和训练全连接BP网络
bp_model = build_bp_network()
bp_model.compile(loss='categorical_crossentropy', optimizer='adam', metrics=['accuracy'])
bp_model.fit(X_train, Y_train, epochs=10, batch_size=32, validation_split=0.2)

# 评估BP网络模型
loss_and_metrics_bp = bp_model.evaluate(X_test, Y_test, batch_size=32)
print('BP network loss and accuracy:', loss_and_metrics_bp)
