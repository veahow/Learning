import requests
import os

url = "http://news.upc.edu.cn/_upload/article/images/b7/64/0a6da2d04abdaec46cc26e7c8110/e2e1d5f3-3bf8-49fd-a574-45481b5af4d4.jpg"
root = "C://Users/veahow/Desktop/"
path = root + url.split('/')[-1]
try:
    if not os.path.exists(root):
        os.mkdir(root)
    if not os.path.exists(path):
        r = requests.get(url)
        with open(path, 'wb') as f:
            f.write(r.content)
            f.close()
            print("图片保存成功")
    else:
        print("图片已存在")
except:
    print("爬取失败")