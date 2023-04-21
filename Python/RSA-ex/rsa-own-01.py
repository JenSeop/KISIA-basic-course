from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP


key = RSA.generate(2048) # 지정된 키 크기(2048 bit) RSA 키 쌍 생성
public_key = key.publickey() # 공개키와 개인키를 키 쌍에서 추출
private_key = key


msg = "Hello, JenSeop!" # 암호화할 평문 메시지
cipher = PKCS1_OAEP.new(public_key) # 공개키를 사용하여 암호화를 위한 암호 객체 생성
ciphertext = cipher.encrypt(msg.encode()) # 메시지(msg)를 암호 객체를 사용하여 암호화
print("Ciphertext:", ciphertext.hex()) # 암호문 출력


cipher = PKCS1_OAEP.new(private_key) # 개인키를 사용하여 복호화를 위한 암호 객체 생성
decrypted_message = cipher.decrypt(ciphertext) # 암호문(ct)를 암호 객체를 사용하여 복호화
decrypted_message = decrypted_message.decode() # 복호화된 메시지를 바이트에서 문자열로 변환
print("Decrypted Message:", decrypted_message.decode()) # 복호화된 평문 메시지 출력