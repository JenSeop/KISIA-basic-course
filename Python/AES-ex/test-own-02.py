from Crypto.Random import get_random_bytes
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad

class AESCipher:

    # block size
    def __init__(self, bs):
        self.bs = 16
        self.sk = get_random_bytes(16)

    def encrypt(self, msg):
        pt = pad(msg.encode(), self.bs)
        iv = get_random_bytes(16)
        cipher = AES.new(self.sk, AES.MODE_CBC, iv)
        ct = cipher.encrypt(pt)
        return iv,  ct
    
    def decrypt(self, ct, iv):
        cipher = AES.new(self.sk, AES.MODE_CBC, iv)
        pt = unpad(cipher.decrypt(ct), self.bs).decode()
        return pt

msg = 'Hello' # 암호화 할 메시지
aes = AESCipher(16) # AESCipher 객체 생성
iv, ct = aes.encrypt(msg) # 암호화
pt = aes.decrypt(ct, iv) # 복호화
print(str(ct)) # 암호화 문
print(str(pt)) # 복호화 문