def getUserChoice():
    choice = int(input(
        "Please select one of the following options:\n"+
        "                1. User registration\n"+
        "                2. User Login\n" +
        "                3. Play the game as a guest\n"))
    return choice
    
def guestQuiz():
    quizChoice = chooseQuiz()
    isPass = takeQuiz(quizChoice)
    if isPass:
        print("Congratulations. You can start the game.")
        
def chooseQuiz():
    choice = int(input("Dear guest, you have to pass one quiz to play the game.\n"+
    " Please select one of the following quizzes: \n" 
    + "    1. Number guessing\n"
    +"    2. Calculate sum\n" ))
    return choice

def takeQuiz(choice):
    if choice == 1:
        isPass = guessingNumber()
    elif choice == 2:
        isPass = calculateSum()
    return True

#number guessing game
def guessingNumber():
    import random
    valid = False
    while not valid:
        try:
            trial_number = 1
            num = random.randint(1,9) #randomise a number from 1 to 9
            while trial_number <= 3 :
                num_guess = int(input("Enter an integer from 1 to 9: "))
                valid = True
                if num_guess == num :
                    print("Congratulations. You guessed it by " +
                          str(trial_number) + " trials!\n")
                    break #ends the game
                elif num_guess < num :
                    trial_number = trial_number + 1
                    print("guess is low")
                    continue #goes back to start of while loop
                elif num_guess > num :
                    trial_number = trial_number + 1
                    print("guess is high")
                    continue #goes back to start of while loop
            else: #if 3 tries are all wrong
                print("Sorry, you exceed the trial limit. Failed.") 
            continue #loops back to game selection
        except ValueError: #if user does not input an integer
            print("Wrong input format. Please try again.\n")
    
#calculate sum game
def calculateSum():
    import random
    valid = False
    while not valid:
        try:
            start_num = random.randint(55,66) #randomise start integer in range 55 to 66
            print("Please calculate the sum for 5 consecutive integers starting from " + str(start_num))
            total_sum = 5*start_num + 10
            sum_guess = int(input("Please enter your answer: "))
            valid = True
            if sum_guess != total_sum :
                print("Sorry, wrong answer. Failed.")
            print("\nYou can start the game now.\n")
            continue #loops back to game selection
        except ValueError: #if user does not input an integer
            print("Wrong input format. Please try again.\n")

#function to create a new user
def getNewUserName(username,userbase):
    if username in userbase:
        print("This user exists. Please choose another username.")
    else:
        return True

#function for getting a strong password    
def getStrongPassword(password):
    #check for length
    if len(password)<8:
        print("Your password is weak. Please enter a new password")
    #check for uppercase
    elif not any(char.isupper() for char in password):
        print("Your password is weak. Please enter a new password.")
    #check for lowercase
    elif not any(char.islower() for char in password):
        print("Your password is weak. Please enter a new password.")
    #check for digit
    elif not any(char.isdigit() for char in password):
        print("Your password is weak. Please enter a new password.")
    else:
        return True    
        
#function to register a new user
def userRegistration(getNewUserName,getStrongPassword):
    while True:
        username = str(input("Input your username: "))
        if getNewUserName(username,userbase): 
            break
    while True:
        password = str(input("Input your password:\n" + 
                "1. the password has at least one upper case letter \n" +
                "2. the password has at least one lower case letter \n" +
                "3. the password has at least one digit \n"))
        if getStrongPassword(password):
            break
    print("New User registered. You can start the game.")
    userbase[username] = password

#function for existing users to log in
def userLogin():
    while True:
        username = str(input("Input username: "))
        if username in userbase.keys():
            password = str(input("Input password: "))
            if (username,password) in userbase.items(): 
                print("Welcome back, " + username + ", You can start the game.")
                break
            else:
                print("Incorrect password.")
        else:
            print("User does not exist.")

def main():
    choice = getUserChoice()
    if choice == 1:
        userRegistration(getNewUserName,getStrongPassword)
    elif choice == 2:
        userLogin()
    elif choice == 3:
        guestQuiz()
        
       
userbase = {
                "Test":"Test12345",
                "Jack":"Test12345",
                "Tom":"Password1" }
main()
