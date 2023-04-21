from Crypto.Random import get_random_bytes
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad

class AESCipher:
    def __init__(self, key):
        self.bs = 16
        self.sk = key

    def encrypt(self, msg):
        pt = pad(msg.encode(), self.bs)
        iv = get_random_bytes(16)
        cipher = AES.new(self.sk, AES.MODE_CBC, iv)
        ct = cipher.encrypt(pt)
        return iv + ct

    def decrypt(self, ct):
        iv = ct[:AES.block_size]
        cipher = AES.new(self.sk, AES.MODE_CBC, iv)
        pt = unpad(cipher.decrypt(ct[AES.block_size:]), self.bs).decode()
        return pt

# 사용법 예시
key = get_random_bytes(16)  # 16바이트 (128비트)의 무작위 키 생성
msg = "Hello, JenSeop!"     # 암호화할 메시지
cipher = AESCipher(key)     # AESCipher 객체 생성

# 암호화
encrypted = cipher.encrypt(msg)
print("암호문:", encrypted)

# 복호화
decrypted = cipher.decrypt(encrypted)
print("복호화된 평문:", decrypted)