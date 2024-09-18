import re
def check_password(password):
    length=len(password)>=8
    uppercase=re.search(r'[A-Z]', password)
    lowercase= re.search(r'[a-z]', password)
    speical_letter= re.search(r'[@#$%^&*()<>/?{}":|<>]',password)
    number= re.search(r'[1-9]', password)
    '''calculating the strength of password'''
    strength=0
    if length:
        strength+=1
    if uppercase:
        strength+= 1
    if lowercase:
       strength+= 1
    if speical_letter:
        strength+= 1
    if number:
        strength+= 1
    return strength

password=input("Enter the password to check :")
output= check_password(password)

''' checking the password stregth weather the password is strong or not'''
if output==5:
    print( "Password is very strong")
elif output>=3:
    print( "Password is moderate strong")
elif output>=1:
    print("Password is weak")
else:
    print("Make the password strong")
