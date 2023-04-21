from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP

# RSA 키 쌍 생성
key = RSA.generate(2048)
public_key = key.publickey()
private_key = key

# 암호화할 평문 메시지
msg = "Hello, ChatGPT!"

# 공개키를 사용하여 암호화
cipher = PKCS1_OAEP.new(public_key)
ciphertext = cipher.encrypt(msg.encode())

print("Ciphertext:", ciphertext.hex())  # 암호문 출력

# 개인키를 사용하여 복호화
cipher = PKCS1_OAEP.new(private_key)
decrypted_message = cipher.decrypt(ciphertext)

print("Decrypted Message:", decrypted_message.decode())  # 복호화된 평문 메시지 출력
