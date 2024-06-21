import requests
from bs4 import BeautifulSoup
import os
import time
import hashlib

def download_images(url, save_folder):
    if not os.path.exists(save_folder):
        os.makedirs(save_folder)
    response = requests.get(url)
    soup = BeautifulSoup(response.content, 'html.parser')
    images = soup.find_all('img', attrs={'data-src': lambda src: src and src.endswith('.jpg')})
    for img in images:
        img_url = img['data-src'] 
        filename = img_url.split('/')[-1]
        unique_suffix = hashlib.md5(img_url.encode()).hexdigest()[:8]
        unique_filename = f"{time.strftime('%Y%m%d%H%M%S')}_{unique_suffix}_{filename}"
        save_path = os.path.join(save_folder, unique_filename)

        try:
            img_data = requests.get(img_url).content
            with open(save_path, 'wb') as file:
                file.write(img_data)
            print(f"Image saved: {save_path}")
        except Exception as e:
            print(f"Failed to download {img_url}: {str(e)}")
url = "https://qq.yh31.com/qt/fj/"
download_images(url, r"image2")