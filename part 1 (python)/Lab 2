import random
while True:
    selection = int(input("Please select one of the following quizzes: \n" 
    + "                   1. Number guessing\n"
    +"                   2. Calculate sum\n" ))

#for wrong game selection
    if selection not in [1,2] :
        print("Wrong option. Bye.")
    
#number guessing game
    elif selection == 1 :
        valid = False
        while not valid:
            try:
                trial_number = 1
                num = random.randint(1,9) #randomise a number from 1 to 9
                while trial_number <= 3 :
                    num_guess = int(input("Enter an integer from 1 to 9: "))
                    valid = True
                    if num_guess == num :
                        print("Congratulations. You guessed it by " + str(trial_number) + " trials!")
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
                    print("Sorry, you exceed the trial limit. Failed")
                print("\nYou can start the game now.\n") 
                continue #loops back to game selection
            except ValueError: #if user does not input an integer
                print("Wrong input format. Please try again.\n")
    
#calculate sum game
    elif selection == 2 :
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
