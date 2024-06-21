import urllib.request
import re
import os

def fetch_images(url, folder):
    if not os.path.exists(folder):
        os.mkdir(folder)
    
    response = urllib.request.urlopen(url)
    html = response.read().decode('utf-8')
    
    img_urls = re.findall(r'src="(https?://.*?\.jpg)"', html)
    
    for img_url in img_urls:
        img_name = img_url.split('/')[-1]
        urllib.request.urlretrieve(img_url, os.path.join(folder, img_name))
        print(f"Downloaded {img_name}")

fetch_images('https://qq.yh31.com/qt/fj/', 'image1')