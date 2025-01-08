#include<stdio.h>
#include<math.h>
void welcome();
void UserInfo(char name[], char gender[], char profession[]);
void displayMenu();
int getChoice();
void SavingsRequired();
void SavingsForGoal();
void Disclaimer();
void summary(float slry, int rrage, int crage, float yfund, float avgmf, float ifl, float erf);

void welcome() {
    printf("\n*********************************");
    printf("\n*         WELCOME!!!!!!!!       *");
    printf("\n*      RetireWell Solutions     *");
    printf("\n*********************************");
    printf("\n Press Enter to continue.........");
    getchar();
}

void UserInfo(char name[], char gender[], char profession[]) {
    printf("\n Enter your name: ");
    fgets(name, 500, stdin);
    printf("\n Enter your gender: ");
    fgets(gender, 100, stdin);
    printf("\n Enter your profession: ");
    fgets(profession, 100, stdin);
}

void displayMenu() {
    printf("\n1) Calculate the savings required to reach your goal");
    printf("\n2) Calculate the amount you need to save");
    printf("\n Choose any one option: ");
}

int getChoice() {
    int choice;
    scanf("%d", &choice);
    getchar();  
    return choice;
}

void SavingsRequired() {
    int crage, rrage, mntlygn, ytr, yrsret;
    float avgmf = 76.00, ifl = 0.03, fi, fa, retcor, reqsav, erf, annsav, monsav, loan;

    float stocks, mutual, estate, gold, fd; 

    printf("\n Enter your current age: ");
    scanf("%d", &crage);
    printf("\n Enter your retirement age: ");
    scanf("%d", &rrage);

    if (rrage>=avgmf||rrage<=crage) {
        printf("\n Invalid retirement age. Please ensure it is less than life expectancy and greater than your current age.\n");
        return;
    }
    printf("\n Enter income required per month after your retirement: ");
    scanf("%d", &mntlygn);
    printf("\n Enter your existing retirement fund: ");
    scanf("%f", &erf);
    printf("\n Please enter the existing debt or loans: ");
    scanf("%f", &loan);
    ytr = rrage - crage;
    fi = mntlygn * pow((1 + ifl), ytr);
    fa = mntlygn * 12;
    yrsret = avgmf - rrage;
    retcor = (fa * yrsret) + loan;
    reqsav = retcor - erf;
    annsav = reqsav / ytr;
    monsav = annsav / 12;

    float monthlySavings = monsav; 
    stocks = monthlySavings * 0.35;
    mutual = monthlySavings * 0.20;
    estate = monthlySavings * 0.15;
    gold = monthlySavings * 0.25;
    fd = monthlySavings * 0.05;

    printf("\n\n===================================================");
    printf("\n Future Monthly Income required: Rs. %.2f", fi);
    printf("\n Total Retirement Corpus Needed: Rs. %.2f", retcor);
    printf("\n Required Savings: Rs. %.2f", reqsav);
    printf("\n Annual Savings Needed: Rs. %.2f", annsav);
    printf("\n Monthly Savings Needed: Rs. %.2f", monsav);
    printf("\n\n Systematic investment for your savings is given below:");
    printf("\n %.2f invested in the stock market", stocks);
    printf("\n %.2f invested in mutual funds", mutual);
    printf("\n %.2f invested in real estate", estate);
    printf("\n %.2f invested in sovereign gold bonds", gold);
    printf("\n %.2f invested in fixed deposits", fd);
    printf("\n===================================================");

    Disclaimer();
}

void SavingsForGoal() {
    int crage, rrage;
    float slry, erf, loan, save, mfund, yfund;
    float avgmf = 76.00, ifl = 0.03;
    float stocks, mutual, estate, gold, fd;

    printf("\n\n Enter your current age: ");
    scanf("%d", &crage);
    printf("\n Enter your retirement age: ");
    scanf("%d", &rrage);

    if (rrage >= avgmf || rrage <= crage) {
        printf("\n Invalid retirement age. Please ensure it is less than life expectancy and greater than your current age.\n");
        return;
    }

    printf("\n Enter your monthly salary: ");
    scanf("%f", &slry);
    printf("\n Enter your existing retirement fund: ");
    scanf("%f", &erf);
    printf("\n Please enter the existing debt or loans: ");
    scanf("%f", &loan);

    save = ((slry * 20) / 100) * 12 * (rrage - crage) + loan - erf;
    yfund = save / (avgmf - rrage);
    mfund = yfund / 12;

    float monthlySavings = (slry * 20) / 100;
    stocks = monthlySavings * 0.35;
    mutual = monthlySavings * 0.20;
    estate = monthlySavings * 0.15;
    gold = monthlySavings * 0.25;
    fd = monthlySavings * 0.05;

    printf("\n\n===================================================");
    printf("\n Monthly saving for your retirement: Rs. %.2f", monthlySavings);
    printf("\n Income you get per year after retirement: Rs. %.2f", yfund);
    printf("\n Income you get per month after retirement: Rs. %.2f", mfund);
    printf("\n\n Systematic investment for your savings is given below:");
    printf("\n %.2f invested in the stock market", stocks);
    printf("\n %.2f invested in mutual funds", mutual);
    printf("\n %.2f invested in real estate", estate);
    printf("\n %.2f invested in sovereign gold bonds", gold);
    printf("\n %.2f invested in fixed deposits", fd);
    printf("\n===================================================");

    Disclaimer();
}

void Disclaimer() {
    printf("\n===================================================");
    printf("\n Note: You should not cross your monthly savings more than 20%% from your monthly income.");
    printf("\n NOTE: While saving regularly is a great step, consider investing your savings in assets like mutual funds,\n stocks, or retirement plans.");
    printf("\n Investing can help you grow your money faster through compounding, providing potentially better returns than traditional savings.");
    printf("\n With careful planning, investments can help you reach your retirement goals more effectively.");
    printf("\n===================================================");
}

int main(void) {
    welcome();
    char name[500], gender[100], profession[100];
    UserInfo(name, gender, profession);
    displayMenu();
    int choice = getChoice();

    switch (choice) {
        case 1:
            SavingsRequired();
            break;
        case 2:
            SavingsForGoal();
            break;
        default:
            printf("\nInvalid choice! Please restart the program and select option 1 or 2.");
    }

    printf("\nThank you for using RetireWell Solutions. We wish you a prosperous retirement journey!");
    return 0;
}

