/*
==================================================================================================================================================================
FILE : 	FINALS Software Project Code.c
AUTHOR : LAURON, JOHN ENRICO D.
DESCRIPTION : 40 item trivia
COPYRIGHT : 12/06/2022
==================================================================================================================================================================
*/

#include <stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<stdbool.h>

void help();
int select_random_question(const char questions[10][256],
        int asked_questions[10]);
bool askTrueFalse(const char question[256], bool answer);
bool askMultipleChoice(const char question[256],
        const char answers[4][256], int answer);
bool askIdentification(const char question[256],
    const char answer[256]);
void getGrade(int points, char grade[8]);

int main()
{
    const char test1questions[10][256] = {
        "The atomic number for lithium is 17.",
        "A cross between a horse and a zebra is called a 'Hobra.'",
        "The black box in a plane is black.",
        "Alliumphobia is a fear of garlic.",
        "Cleopatra was of Egyptian descent.",
        "Giraffes say moo.",
        "Coffee is made from berries.",
        "Tomatoes are fruit.",
        "Mount Fuji is the highest mountain in Japan.",
        "The skull is the strongest bone in the human body.",
    };
    const bool test1answers[10] = { false, false, false, true, true, true, true, true, true, true };

    const char test2questions[10][256] = {
        "What is the type of protein that helps build and maintain muscle?",
        "Who first invented the computer?",
        "Which among the people listed below is one of the people who founded Facebook?",
        "What is the organ that is in-charge of circulating blood in the system?",
        "What is the organ that helps with digestion by dispensing and storing bile?",
        "What is known as the structural framework of the cell?",
        "Which part of the brain is responsible for cognitive thinking and coordinating motor movement?",
        "Which among the four is not considered a cell?",
        "What bodily chemical is released when a person is exercising?",
        "How long can a person survive without drinking water?"
    };
    const char test2choices[10][4][256] = {
        { "Structural protein", "Whey protein", "Antibodies\t", "Transport protein" },
        { "John Herschel", "Rick Grimes", "Charles Babbage", "Hiram Maxim" },
        { "Mark Zuckerberg", "Elon Musk", "Charles Hugh", "Jonathan Lugh" },
        { "Lungs", "Spleen", "Heart", "Brain" },
        { "Gallbladder", "Heart", "Lungs", "Stomach" },
        { "Cilia", "Hydrostatic Skeleton", "Eukaryote", "Cytoskeleton" },
        { "Parietal lobe", "Frontal lobe", "Occipital lobe", "Temporal lobe" },
        { "Virus", "Bacteria", "Platelet", "RBC" },
        { "Endorphin\t", "Calcium", "Carbon Dioxide", "Phosphorus" },
        { "1 week", "2 days", "4 days", "3 days" }
    };
    const int test2answers[10] = { 2, 3, 1, 3, 1, 4, 2, 1, 1, 4 };

    const char test3questions[10][256] = {
        "It is the process by which plants use sunlight, water, and carbon dioxide to create oxygen and energy in the form of sugar. (Spnoioehtytshs)",
        "Who is credited with creating C? (Sndnei Rtihcei)",
        "Who was the first president of the Philippines?(Emlioi Agnlaodui)",
        "What is the oldest Philippine City? (Ubec Yict)",
        "What is the largest organ in the body? (Ksni)",
        "What blood cell is important in carrying oxygen throughout the body? (Erd Doblo Lecl)",
        "Who was the first person to go to the moon? (Inle Ratognsrm)",
        "Where in the atmosphere is the ozone layer located? (Phtosresteas)",
        "Who was the first dog to go to space? (Klaia)",
        "Who invented the Telephone? (Dxarlanre Mgarah Lebl)"
    };
    const char test3answers[10][256] = {
        "photosynthesis", "Dennis Ritchie",
        "Emilio Aguinaldo", "Cebu City",
        "skin", "red blood cell",     
        "Neil Armstrong", "stratosphere",
        "Laika", "Alexander Graham Bell"
    };

    const char test4questions[10][256] = {
        "A salesman sold twice as much pears in the afternoon than in the morning. If he sold 360 kilograms of pears that day, how many kilograms did he sell in the morning and how many in the afternoon?",
        "A student chose a number and divide it by 5. Then subtracted 154 from the result and got 6. What was the number did the student chose?",
        "Enrico and Shayne can clean the house together in 6 hours. If it takes Enrico 10 hours working alone, how long will it take Shayne working alone?",
        "Walter is 2 years from being twice as old as Jesse. The sum of twice Walter's age and three times Jesse's age is 66. How old is Jesse?",
        "The perimeter of a rectangle is 104 inches. The width is 6 inches less than 3 times the length. Find the width of the rectangle.",
        "Tom has twice as many cousins as Robert. Jerry has 5 cousins, which is 11 less than Tom has. How many cousins does Robert have?",
        "Justin earned scores of 85, 92, and 95 on his science tests. What does he need to earn on his next science test to have an average (arithmetic mean) of 93\%?",
        "A flight from Cebu to Singapore took 5 hours and covered 3,060 miles. What was the plane's average speed?",
        "Musashi is combining two 6-inch pieces of wood with a piece that measures 4 inches. How many total inches of wood does he have?",
        "If the expression 9y-5 represents a certain number, which of the following could NOT be the translation?"
    };
    const char test4choices[10][4][256] = {
        {
            "The salesman sold 100 kg in the morning and 200 in the afternoon.",
            "The salesman sold 120 kg in the morning and 240 in the afternoon.",
            "The salesman sold 150 kg in the morning and 260 in the afternoon.",
            "The salesman sold 110 kg in the morning and 220 in the afternoon."
        },
        { "900", "700", "600", "800" }, { "11 hours", "15 hours", "16 hours", "4 hours" },
        { "10", "15", "18", "20" }, { "14.5 inches", "13.5 inches", "37.5 inches", "18 inches" },
        { "17", "21", "4", "8" }, { "93", "100", "85", "88" }, { "545 mph", "615 mph", "515 mph", "612 mph" },
        { "10 inches", "16 inches", "8 inches", "12 inches" },
        {
			"five less than nine times y\t", "five less than the sum of 9 and y",
			"the difference between 9y and 5", "the product of 9 and y, decreased by 5"
		}
    };
    const int test4answers[10] = { 2, 4, 2, 1, 3, 4, 2, 4, 2, 2 };
	int test1progress, test2progress, test3progress, test4progress;
	int test1points = 0,
		test2points = 0,
		test3points = 0,
		test4points = 0,
		totalpoints = 0;
	int test1asked[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	int test2asked[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	int test3asked[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	int test4asked[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	char grade[8];

	system("color 0a");
	char choice;
	char playername[20];
	mainhome:
		system("cls");
		printf("\t\t\t\t\tWELCOME TO OUR T3via!\n");
     printf("\n\n\t\t => Press S to Start the Game\t\t => press H for Help\n");
     printf("\n\t\t\t\t\t=> press Q to Quit\n");
     printf("\n\n\t\t\t => ");
     choice=toupper(getch());
    if (choice=='H')
     {
     	help();
     	getch();
     	goto mainhome;
	 }
	else if (choice=='Q')
	{
	 printf("\n\n\t\t\t\t\tThe T3via has ended\t\t\n\n");
		return 0;
	}
	else if (choice=='S')
	{
		system("cls");
		
		printf("\n\n\t\t\tREGISTER YOUR NAME : ");
     gets(playername);
     
     system("cls");
    printf("\n\t\t ------------------  Welcome %s to our T3via! --------------------------",playername);
    printf("\n\n\n\t\t\t ------------------ GRADING SYSTEM ------------------\n");
		   printf("\n\t\t\t => 101-110 = A+");
		   printf("\n\t\t\t => 96-100 = A");
		   printf("\n\t\t\t => 91-95 = B");
		   printf("\n\t\t\t => 86-90 = C");
		   printf("\n\t\t\t => 81-85 = D");
		   printf("\n\t\t\t => 76-80 = E");
		   printf("\n\t\t\t => 70-75 = F\n\n");
    printf("\n\n\n => Press S to start the game!\n");
    printf("\n => Press any other key to return to the main menu...");
    if (toupper(getch())=='S')
    	{
		    goto t3via;
        }
	else
		{
        goto mainhome;
       system("cls");
       }
       
    t3via:
		srand(time(NULL));

		system("cls");
		printf("Test I: Input 1 if the statement is true and 0 if the statement is false. (1pt. each)\n\n");

		for (test1progress = 0; test1progress < 10; ++test1progress) {
			int question_index;

			question_index = select_random_question(test1questions, test1asked);

			printf("%d. ", test1progress + 1);

			if (askTrueFalse(test1questions[question_index], test1answers[question_index])) {
				++test1points;
				printf("You have scored 1 point.\n");
			} else {
				printf("You have scored 0 points.\n");
			}
			printf("\n");
		}

		printf("Your total score in test I is: %d\n\n", test1points);
		printf("=> Press any key to continue to test II...");
		getch();

		system("cls");
		printf("Test II: Input the number of the correct answer (1-4 only). (2pts. each)\n\n");

		for (test2progress = 10; test2progress < 20; ++test2progress) {
			int question_index;

			question_index = select_random_question(test2questions, test2asked);

			printf("%d. ", test2progress + 1);

			if (askMultipleChoice(test2questions[question_index], test2choices[question_index], test2answers[question_index])) {
				test2points += 2;
				printf("You have scored 2 points.\n");
			} else {
				printf("You have scored 0 points.\n");
			}
			printf("\n");
		}

		printf("Your total score in test II is: %d\n\n", test2points);
		printf("=> Press any key to continue to test III...");
		getch();

		system("cls");
		printf("Test III: Identification. Identify what is being asked in the question. (3 pts. each)\n\n");

		for (test3progress = 20; test3progress < 30; ++test3progress) {
			int question_index;

			question_index = select_random_question(test3questions, test3asked);

			printf("%d. ", test3progress + 1);

			if (askIdentification(test3questions[question_index], test3answers[question_index])) {
				test3points += 3;
				printf("You have scored 3 points.\n");
			} else {
				printf("You have scored 0 points.\n");
			}
			printf("\n");
		}

		printf("Your total score in test III is: %d\n\n", test3points);
		printf("=> Press any key to continue to test IV...");
		getch();
		
		system("cls");
		printf("Test IV: Input the number of the correct answer (1-4 only). (5pts. each)\n\n");

		for (test4progress = 30; test4progress < 40; ++test4progress) {
			int question_index;

			question_index = select_random_question(test4questions, test4asked);

			printf("%d. ", test4progress + 1);

			if (askMultipleChoice(test4questions[question_index], test4choices[question_index], test4answers[question_index])) {
				test4points += 5;
				printf("You have scored 5 points.\n");
			} else {
				printf("You have scored 0 points.\n");
			}
			printf("\n");
		}

		printf("Your total score in test II is: %d\n\n", test4points);
		printf("=> Press any key to continue to test III...");
		getch();

		/* Grade performance on test */
		system("cls");
		totalpoints = test1points + test2points + test3points + test4points;
		getGrade(totalpoints, grade);

		printf("Your total grade is: %d\n\n", totalpoints);

		if (strcmpi(grade, "FAIL")) {
			printf("Grade %s", grade);
		} else {
			printf("You have failed.");
		}
		printf("\n\n");

		getch();

	return 0;
	
	}
}

void help()
{
	system("cls");
	printf("\n\t\t ------------------  HELP --------------------------\n");
	printf("\n => It is basically a trivia with 10 questions each level. \n");
	printf("\n => Test 1 (True or False) with 1 point each question. \n");
	printf("\n => Test 2 (Multiple Choice) with 2 points each question. \n");
	printf("\n => Test 3 (Identification) with 3 points each question. \n");
	printf("\n => Test 4 (Math Problems with Multiple Choice) with 5 points each question. \n");
	printf("\n => After the T3via, there will be a grading system where if you score below 75 means that you didn't passed the T3via. \n");
	printf("\n => And if you score above 75 means that you passed the T3via. \n");
	printf("\n\n Press any other key to return to the main menu... ");
}

int select_random_question(const char questions[10][256],
        int asked_questions[10]) {
    int questionindex, askedindex;
    bool asked = true;

    while (asked) {

        questionindex = rand() % 10;
        
        for (askedindex = 0; askedindex < 10; ++askedindex) {
            int askedquestion = asked_questions[askedindex];

            if (askedquestion == -1) {
                asked = false;
                break;    
            }

            if (questionindex == askedquestion) break;
        }

        if (!asked) {
            asked_questions[askedindex] = questionindex;
        }
    }

    return questionindex;
}

bool askTrueFalse(const char question[256], bool answer) {
    bool correct, validinput = false, input;

    fflush(stdin);

    printf("%s\n\nAnswer: ", question);

    while (!validinput) {
        switch (getche()) {
            case '1':
                validinput = true;
                input = true;
                break;
            case '0':
                validinput = true;
                input = false;
                break;
            default:
                break;
        }
    }

    correct = input == answer;

    printf("\n\n");
    if (correct) {
        printf("Correct!\n");
    } else {
        printf("Wrong!\n");
    }
    
    return correct;
}

bool askMultipleChoice(const char question[256],
        const char answers[4][256], int answer) {
    bool correct, validinput = false;
    int input, index;

    fflush(stdin);

    printf("%s\n\n", question);

    for (index = 0; index < 4; ++index) {
        printf("(%d) ", index + 1);
        printf("%s\t\t", answers[index]);

        if (index % 2) printf("\n");
    }
    printf("\nAnswer: ");

    while (!validinput) {
        switch (getche()) {
            case '1':
                validinput = true;
                input = 1;
                break;
            case '2':
                validinput = true;
                input = 2;
                break;
            case '3':
                validinput = true;
                input = 3;
                break;
            case '4':
                validinput = true;
                input = 4;
                break;
            default:
                break;
        }
    }

    correct = input == answer;

    printf("\n\n");
    if (correct) {
        printf("Correct!\n");
    } else {
        printf("Wrong. The correct answer is (%d).\n", answer);
    }
    
    return correct;
}

bool askIdentification(const char question[256], const char answer[256]) {
    bool correct;
    char input[256];

    fflush(stdin);

    printf("%s\n\nAnswer: ", question);

    scanf("%[^\n]s", input);

    correct = !strcmpi(input, answer);

    printf("\n");
    if (correct) {
        printf("Correct!\n");
    } else {
        printf("Wrong. The correct answer is \"%s\".\n", answer);
    }
    
    return correct;
}

void getGrade(int points, char grade[8]) {
    bool gradeAplus = (points >= 101 && points <= 110),
         gradeA = (points >= 96 && points <= 100),
         gradeB = (points >= 91 && points <= 95),
         gradeC = (points >= 86 && points <= 90),
         gradeD = (points >= 81 && points <= 85),
         gradeE = (points >= 76 && points <= 80),
         gradeF = (points >= 70 && points <= 75),
         gradefail = (points >= 0 && points <= 69);

    if (gradeAplus) {
        strcpy(grade, "A+");
    } else if (gradeA) {
        strcpy(grade, "A");
    } else if (gradeB) {
        strcpy(grade, "B");
    } else if (gradeC) {
        strcpy(grade, "C");
    } else if (gradeD) {
        strcpy(grade, "D");
    } else if (gradeE) {
        strcpy(grade, "E");
    } else if (gradeF) {
        strcpy(grade, "F");
    } else if (gradefail) {
        strcpy(grade, "FAIL");
    } else {
        strcpy(grade, "ERROR");
    }
}
