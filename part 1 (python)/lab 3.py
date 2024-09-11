print("User registration:")
userbase = {
        "Test":"Test12345",
        "Jack":"Test12345",
        "Tom":"Password1" }

#check for duplicate username
while True:
    username = str(input("Input your username: "))
    if username in userbase:
        print("This user exists. Please choose another username.")
        continue
    else:
        break

while True:
    password = str(input("Input your password:\n" + 
    "1. the password has at least one upper case letter \n" +
    "2. the password has at least one lower case letter \n" +
    "3. the password has at least one digit \n"))
     
#password checking
    def passwordCheck(password):
        if len(password)<8: #check for length
            print("Your password is weak. Please enter a new password")
        else:
            #check for uppercase
                if not any(char.isupper() for char in password): 
                    print("Your password is weak. Please enter a new password.")
                    
            #check for lowercase
                elif not any(char.islower() for char in password): 
                    print("Your password is weak. Please enter a new password.")

            #check for digit
                elif not any(char.isdigit() for char in password): 
                    print("Your password is weak. Please enter a new password.")

            #password meets requirements
                else:
                    print("Your password is strong enough. User registered.")
                    userbase[username] = password
                    print("The users in system\n", userbase)
                    return True
        
    if passwordCheck(password):
        break
