#include <iostream>
#include <fstream>
using namespace std;

class Cholesterol{
private:
    float amount = 0.00;
    string cholResult = "No Result - you did not input your cholesterol level";
public:
    void setCholAmount(float a){amount = a;}
    float getCholAmount(){return amount;}    //for writing in txt
    string getCholResult()const{return cholResult;}  //for writing in txt
    void readChol(){
        cout << "[Analysis of cholesterol amount]" << endl
        << "\tEnter cholesterol amount (in mg/dL): ";

    }
    string calcChol(){
        if (amount < 200) { //cholesterol, mg/dL
            cholResult = "\tDesirable.";
        }
        else if ((amount >= 200) && (amount <= 239)) {
            cholResult =
            "\tBorderline of high. Therefore you must skip the high Cholesterol\n"
            "\tfood such as fatty cuts of meat, full-fat, deep fried fast foods,\n"
            "\tprocessed foods such as biscuits and pastries, takeaway foods such\n"
            "\tas hamburgers and pizza, coconut oil, butter, etc.";
        }else if (amount >= 240) {
            cholResult = "High. You must console a doctor.\n";
        }
        return cholResult;
    }
    void display(){
        cout << "[Result of your cholesterol analysis]" << endl;
        if(amount == 0){
            cout << "\tNo result - you did not input your cholesterol level" << endl;
        }else{
            cout << "\tYour cholesterol rate is " << amount << " mg/dL, which is\n" << calcChol();
        }
    }
    friend istream &operator>>(istream &input, Cholesterol &chol);

};

istream &operator>>(istream &input, Cholesterol &chol){
    input>>chol.amount;
    return input;
}

class BloodPressure{
private:
    int sbp = 0;
    int dbp = 0;
    int result1 = 0;
    int result2 = 0;
    string SDPresult = "No result - you didn't input your blood pressure";  //for writing txt
    string DBPresult = "No result - you didn't input your blood pressure";  //for writing txt
public:
    string getSDPresult()const{return SDPresult;}   //for writing txt
    string getDBPresult()const{return DBPresult;}   //for writing txt
    void readPressure() {
	    cout << "[Analysis of your blood pressure]" << endl;
	    cout << "\tEnter your systolic blood pressure in mmHg: ";
	    cin >> sbp;
	    cout << "\tEnter your diastolic blood pressure in mmHg: ";
	    cin >> dbp;
    }
    void calcPressure() {
	    if (sbp > 0  && sbp <= 90){result1 = 1;}
	    else if (sbp > 90  && sbp <= 120){result1 = 2;}
	    else if (sbp > 120 && sbp <= 140){result1 = 3;}
	    else if (sbp > 140 && sbp <= 160){result1 = 4;}
	    else if (sbp > 160){ result1 = 5;}

	    if (dbp > 0 && dbp <= 60){result2 = 1; }
	    else if (dbp > 60 && dbp <= 80){result2 = 2; }
	    else if (dbp > 80 && dbp <= 90){result2 = 3; }
	    else if (dbp > 90 && dbp <= 100){result2 = 4; }
	    else if (dbp > 100){result2 = 5; }

             switch (result1) {
		        case 1: SDPresult = "\tYour SBP is low"; break;
		        case 2: SDPresult = "\tYour SBP is normal"; break;
		        case 3: SDPresult = "\tYour SBP indicates pre-hypertension"; break;
		        case 4: SDPresult = "\tYour SBP indicates stage 1 hypertension"; break;
		        case 5: SDPresult = "\tYour SBP indicates stage 2 hypertension"; break;
		    }

            switch (result2) {
		        case 1: DBPresult = "\tYour DBP is low"; break;
		        case 2: DBPresult = "\tYour DBP is normal"; break;
		        case 3: DBPresult = "\tYour DBP indicates pre-hypertension"; break;
		        case 4: DBPresult = "\tYour DBP indicates stage 1 hypertension"; break;
		        case 5: DBPresult = "\tYour DBP indicates stage 2 hypertension"; break;
            }
             }
    void display() {
	    if (result1 == 0 && result2 == 0) {
		    cout << "[Result of your blood pressure analysis]" << endl;
            cout << "\tno Result - you didn't input your blood pressure" << endl;
	    } else {
            cout << "[Result of your diastolic blood pressure(DBP) analysis]" << endl;
		    cout << DBPresult << endl;
            cout << "[Result of your systolic blood pressure(SBP) analysis]" << endl;
            cout << SDPresult << endl;
	    }

    }
};

class BMI{
private:
	float height;
	float weight;
	float bmi = 0.0;
public:
    void setHeight(float h){height = h;}
    void setWeight(float w){weight = w;}
    float getHeight() {return height;}
    float getWeight() {return weight;}
    float getBMI() {return bmi;}
    void calcBMI() {
         bmi = (weight / height / height)*10000;}
    string resultofBMI() {
        if (bmi < 24.0)                    { return  "you are normal";}
        else if (bmi > 24.0 && bmi < 29.0) { return  "you are overweight";}
        else if (bmi > 29.0 && bmi < 39.0) { return  "you are obese";}
        else if (bmi > 30.0)               { return  "you are morbidly obese";}
    }
    void displayBMI() {

        cout << "[Result of your body mass index analysis]" << endl;
        cout << "\tYour BMI is: " << bmi << endl<<" [ "<<resultofBMI()<<" ]"<<endl;

    }
};

class BMR: public BMI{
private:
	float _BMR;
    int gender = 5;
	float age;
public:
	void setGenderAtBMR(int g) {gender = g;}
	void setAge(int a) {age = a;}
	int getGenderAtBMR() {return gender;}
    int getAge()const {return age;}
    float getBMR()const{return _BMR;}
    void calcBMR() {
        if (gender == 1) {
          _BMR = 66 + (13.7 * getWeight()) + (5 * getHeight()) - (6.8 * age);
        } else {
          _BMR = 655 + (9.6 * getWeight()) + (1.8 * getHeight()) - (4.7 * age);
        }
    }
   virtual void display(){
        cout << "[Result of your BMR analysis]" << endl;
        cout << "\tYour BMR is: " << _BMR << endl;
    }
};

class Calories: public BMR{
private:
	float act_level = 0.0;
	int chooseoption;
	float CalCalorie = 0.0;
public:
	void readCalorie(){
        A:
        cout
        << "[Analysis of your calories]\n"
        << "Please input your activity levels\n\n"
        << "Exercise: 15-30 minutes of elevated heart rate activity. \n"
        << "Intense exercise: 45-120 minutes of elevated heart rate activity. \n"
        << "Very intense exercise: 2+ hours of elevated heart rate activity.\n\n"
        << "\tActivity Level:\n"
        << "\t(1) Sedentary: little or no exercise \n"
        << "\t(2) Light Exercise/sports 1-3 day/week \n"
        << "\t(3) Medium Exercise/sports 3-5 day/week \n"
        << "\t(4) Hard Exercise/sports 6-7 day/week \n"
        << "\t(5) Intense Exercise/sports, physical job or twice/day training \n"
        << "\tINPUT: ";
        cin >> chooseoption;
        if (chooseoption == 1) { act_level = 1.2; }
        else if (chooseoption == 2) { act_level = 1.375; }
        else if (chooseoption == 3) { act_level = 1.55; }
        else if (chooseoption == 4) { act_level = 1.725; }
        else if (chooseoption == 5) { act_level = 1.9; }
        else { cout << "Input error try again. \n "; goto A; }
        cout << endl;
    }
    void calcCalorie(){
        CalCalorie = (BMR::getBMR() * act_level);
    }
    void changeCalorie() {
        B:
        cout
        << "\tDaily calorie needs based on activity level = " << CalCalorie << endl
        << "\tIf you want to lose weight or, maintain same weight, choose option below: \n"
        << "\t(1) Maintain weight          " << CalCalorie       << " (100%) Calories/day " << endl
        << "\t(2) Mild weight loss weight  " << CalCalorie * 0.88 << " (88%) Calories/day " << endl
        << "\t(3) Weight loss              " << CalCalorie * 0.75 << " (75%) Calories/day " << endl
        << "\t(4) Extreme weight loss      " << CalCalorie * 0.50 << " (50%) Calories/day " << endl
        << "\tINPUT: ";
        cin >> chooseoption;
        if (chooseoption == 1) { CalCalorie = CalCalorie; }
        else if (chooseoption == 2) { CalCalorie = CalCalorie * 0.88; }
        else if (chooseoption == 3) { CalCalorie = CalCalorie * 0.75; }
        else if (chooseoption == 4) { CalCalorie = CalCalorie * 0.50; }
        else { cout << "Input error try again. \n "; goto B; }
        cout << endl;
    }
    float getCalorie(){return CalCalorie;}
    virtual void display(){ cout<<"The amount of calories you can take is "<< CalCalorie<<" Calories/day. \n";}
};

class FoodIntake: public BMR{
private:
	string Fat_Oil_Sweet = "No data";
	string Portions = "No data";
	string Dairy = "No data";
	string FruitsVeg = "No data";
	string Carbohydrates = "No data";
	string Water = "No data";
	float calories = 0;
	int amount = 0;
	int specific_calories = 0;

public:
    string getFats()const{return Fat_Oil_Sweet;}
    string getPortions()const{return Portions;}
    string getDairy()const{return Dairy;}
    string getFruitVeg()const{return FruitsVeg;}
    string getCarbs()const{return Carbohydrates;}
    string getWater()const{return Water;}

    void foodIntakeMenu(){
        //Menu
        cout
        << "[Analysis of the food you've eaten today]\n"
        << "Please choose the food intake amounts:\n";

        A:
        cout
        << "Fats, oil and Sweets: such as ice-cream, donuts, etc.\n"
        << "\t(1) small amount\n\t(2) medium amount\n\t(3) large amount\n\tINPUT: ";
        cin >> amount;
        if (amount == 1) {
            calories += 150; Fat_Oil_Sweet =
            "great, but it's better if you can avoid it.\n";
        } else if (amount == 2) {
            calories += 300; Fat_Oil_Sweet = "not great. \n\tPlease, make it small amount or, it's better if you can avoid it.\n";
        } else if (amount == 3) {
            calories += 500; Fat_Oil_Sweet = "bad. \n\tIt is bad for your health. Please, make it small amount or, it's better if you can avoid it.\n";
        } else {cout << "Input error try again. \n "; goto A;}
        amount = 0;

        B:
        cout
        << "Choose your Protein source: \n"
        << "\t(1) Fish\n\t(2) Meat\n\t(3) Egg\n\tINPUT: ";
        cin >> amount;
        try {
            if (amount == 1) {calories += 180; Portions = "great. It's Good for you.\n";}
            else if (amount == 2) {throw 0;}
            else if (amount == 3) {calories += 78; Portions = "great. It's Good for you.\n";}
            else {cout << "Input error try again. \n "; goto B;}
        }
        catch (...) {
            amount = 0;
            cout << "Meat type:\n\t(1) Beef\n\t(2) Lame and mutton\n\t(3) Chicken-meat\n\tINPUT: ";
            cin >> amount;
            if (amount == 1){
                C1:
                cout << "\tBeef amount in gram: ";
                cin >> specific_calories;
                calories += (specific_calories * 250) / 100;
                if ((specific_calories > 0)&&(specific_calories <= 70)) {
                    Portions = "great. \n\tPlease, take Beef once or twice a week not more then 70gm \n";
                } else if (specific_calories > 70) {
                    Portions = "bad for your health. \n\tPlease, take Beef once or twice a week not more then 70gm \n";
                } else { cout << "Input error try again. \n "; goto C1; }
            } else if (amount == 2) {
                C2:
                cout << "\tLame and mutton amount in gram: ";
                cin >> specific_calories;
                calories += (specific_calories * 294) / 100;
                if ((specific_calories > 0) && (specific_calories <= 70)) {
                    Portions = "great. Please, take Lame and mutton once or twice a week not more then 70gm \n";
                } else if (specific_calories > 70) {
                    Portions = "bad for your health. \n\tPlease, take Lame and mutton once or twice a week not more then 70gm \n";
                } else { cout << "Input error try again. \n "; goto C2; }
            } else if (amount == 3) {
                C3:
                cout << "\tChicken-meat amount in gram: ";
                cin >> specific_calories;
                calories += (specific_calories * 239) / 100;
                if ((specific_calories > 0) && (specific_calories <= 70)) {
                    Portions = "great. Please, do not take Chicken-meat more then 110gm \n";
                } else if (specific_calories > 70) {
                    Portions = "bad for your health. \n\tPlease, do not take Chicken-meat more then 110gm \n";
                } else { cout << "Input error try again. \n "; goto C3; }
            }
        }

        D:
        cout
        << "Dairy products such as milk, cheese, butter, yogurts etc.\n"
        << "\t(1) Do not take\n\t(2) 1-3 times a day\n\t(3) more then 3 times a day\n\tINPUT: ";
        cin >> amount;
        if (amount == 1) {Dairy = "not good. You should take 1-3 times a day.\n";}
        else if (amount == 2) {
            cout << "\tHow much do you take in gram?: ";
            cin >> specific_calories;
            calories += (specific_calories * 49) / 100;
            Dairy = "good. Please, continue to take it every day.\n";
        } else if (amount == 3) {
            cout << "\tHow much do you take in gram?: ";
            cin >> specific_calories;
            calories += (specific_calories * 49) / 100;
            Dairy = "not good. Please, you should take 1-3 times a day not more then that.\n";
        } else { cout << "Input error try again. \n "; goto D; }
        amount = 0;

        D1:
        cout
        << "Fruits and vegetables:\n\t(1) less than 5 times a day\n\t(2) equal our, more than 5 times a day\n\tINPUT: ";
        cin >> amount;
        if (amount == 1) {
            cout << "\tHow much do you take in gram?: ";
            cin >> specific_calories;
            calories += (specific_calories * 65) / 100;
            FruitsVeg = "not good. \n\tPlease, continue to take Fruits and vegetables 5 times a day.\n";
        } else if (amount == 2) {
            cout << "\tHow much do you take in gram?: ";
            cin >> specific_calories;
            calories += (specific_calories * 65) / 100;
            FruitsVeg = "good. \n";
        } else { cout << "Input error try again. \n "; goto D1; }
        amount = 0;

        F:
        cout
        << "Carbohydrates such as rice, potatoes, pasta, bread, etc. \n";
        cout << "\tHow much do you take in gram?: ";
        cin >> specific_calories;
        calories += (specific_calories * 4);
        if ((specific_calories > 0) && (specific_calories <= 300)) {Carbohydrates = "good.\n";}
        else if (specific_calories > 300) { Carbohydrates = "bad. Too much carbohydrates "
            "are bad for your health.\n";
        } else { cout << "\nInput error try again. \n "; goto F; }


        if (BMR::getGenderAtBMR() == 1) {
            M:
            cout
            << "Daily consumption amount of Water per day: \n"
            << "\t(1) 15.5 cups (3.7 liters)\n\t(2) less then 15.5 cups (3.7 liters)\n\t(3) more then 15.5 cups (3.7 liters)\n\tINPUT: ";
            cin >> amount;
            if (amount == 1) { Water = "good.\n"; }
            else if (amount == 2) {
                Water = "not good. You should take 15.5 cups (3.7 liters) per day.\n";
            } else if (amount == 3) {
                Water = "good. But, you should take 15.5 cups (3.7 liters) per day.\n";
            } else { cout << "Input error try again. \n "; goto M; }
        } else {
            W:
            cout
            << "Daily consumption amount of Water per day: \n"
            << "\t(1) 11.5 cups (2.7 liters)\n\t(2) less then 11.5 cups (2.7 liters)\n\t(3) more then 11.5 cups (2.7 liters)\n\tINPUT: ";
            cin >> amount;
            if (amount == 1) { Water = "good.\n"; }
            else if (amount == 2) {
                Water = "not good. You should take 11.5 cups (2.7 liters) per day.\n";
            } else if (amount == 3) {
                Water = "good. But, you should take 11.5 cups (2.7 liters) per day.\n";
            } else { cout << "Input error try again. \n "; goto W; }
        }
        cout << endl;
    }
    float foodCalories(){
       return calories;
    }
    void feedbackFood(){
        cout
        << "[Result of your food intake analysis]\n"
        << "\tDaily consumption amount of Fats, oil and Sweets is: " << Fat_Oil_Sweet << endl
        << "\tDaily consumption amount of Protein is: " << Portions << endl
        << "\tDaily consumption amount of Dairy product is: " << Dairy << endl
        << "\tDaily consumption amount of Fruits and vegetables is: " << FruitsVeg << endl
        << "\tThe Institute of Medicine recommends all adults to get 45% to 65% of\n"
        << "\ttheir daily calories from carbs, which is 203 to 293 grams per day.\n"
        << "\tDaily consumption amount of Carbohydrates is: " << Carbohydrates << endl
        << "\tDaily consumption amount of Water per day is: " << Water << endl;
    }
};

class Patient{
private:
	string name;
    int gender;
    float heightAtPatient;
    int ageAtPatient;
    float weightAtPatient;
	FoodIntake *food_obj;
	Cholesterol chol_obj;
	BloodPressure blood_obj;
	Calories *cal_ob;
    BMR *bmr_obj;
public:
	Patient(FoodIntake *food_obj, Calories *cal_obj) {
	    this->food_obj = food_obj;
	    food_obj = new FoodIntake;
	    cal_ob=cal_obj;
	    cal_ob = new Calories;
	   // bmr_obj=cal_ob; //Polymorphism applied
    }

    void setName(string n) {name = n;}
    string getName()const {return name;}

    //accessing plood pressure functions
    void readBP() {blood_obj.readPressure();}
    void calcBP() {blood_obj.calcPressure();}
    void dispBP() {blood_obj.display();}

    //accessing calorie functions
    void readCalorie() {cal_ob->readCalorie();}
    void calcCalorie() {cal_ob->calcCalorie(); cal_ob->changeCalorie();}
    void dispCalorie() {cal_ob->display();}   //Polymorphism applied
    float getCalorieAmount() {return cal_ob->getCalorie();}

    //accessing cholesterol functions
    void readChol() {chol_obj.readChol(); cin>>chol_obj; cout<<endl;}
    void dispChol() {chol_obj.display();}

    //accessing foodintake functions
    void readFI() {food_obj->foodIntakeMenu();}
    void dispFI() {food_obj->feedbackFood();}

    //calculating bmi and bmr
    void calculateBMI_BMR(){
        food_obj->calcBMI();
        food_obj->calcBMR();
        cal_ob->calcBMI();
        cal_ob->calcBMR();
    }

    void ReadAll(){
    //read name
	cout << "First of all, please tell us about yourself:\nWhat's your name?: ";
	getline(cin, name);
    cout << endl;

    //read age
    cout << "How old are you?: ";
    cin >> ageAtPatient;
    food_obj->setAge(ageAtPatient);
    cal_ob->setAge(ageAtPatient);
    cout << endl;

    //read gender
    A:
    cout << "('1' for male, or '2' for female)" << endl
    << "What is your gender?: ";
    cin >> gender;
    if(gender != 1 && gender != 2){
        cout << "invalid input, try again" << endl;
        goto A;
    }
    food_obj->setGenderAtBMR(gender);
    cal_ob->setGenderAtBMR(gender);
    cout << endl;

    //read height
    cout << "How high are you? (in centimeters): ";
    cin >> heightAtPatient;
    food_obj->setHeight(static_cast<float>(heightAtPatient));
    cal_ob->setHeight(static_cast<float>(heightAtPatient));
    cout << endl;

    //read weight
    cout << "How heavy are you? (in kilograms): ";
    cin >> weightAtPatient;
    food_obj->setWeight(static_cast<float>(weightAtPatient));
    cal_ob->setWeight(static_cast<float>(weightAtPatient));
    cout << endl;
    }

    //prints to txt file
    void printOutReport(){
    ofstream outfile("Food_intake_analysis_report.txt", ios::out);
        if(outfile.is_open()){
            outfile
            << "********* Food intake analysis report *********\n\n"
            << "Patient name     : " << name << endl;

            if(gender == 1){outfile << "Gender           : Male" << endl;}
            else{outfile << "Gender           : Female" << endl;}

            outfile
            << "Age              : " << food_obj->getAge() <<" Years" << endl
            << "Height           : " << food_obj->getHeight() <<" CM"<< endl
            << "Weight           : " << food_obj->getWeight() <<" KG "<< endl
            << "Cholesterol rate : " << chol_obj.getCholAmount()<<" mg/dL "<< endl
            << "BMI result       : " << food_obj->getBMI() <<"["<<food_obj->resultofBMI()<<"]" << endl
            << "BMR result       : " << food_obj->getBMR() << endl
            << "Blood pressure (SDP) results: " << blood_obj.getSDPresult() << endl
            << "Blood pressure (DBP) results: " << blood_obj.getDBPresult() << endl<<endl
            << "The amount of calories you should take " << cal_ob->getCalorie()<<" Calories/day."<< endl
            << "But the amount of calories you are taking " << food_obj->foodCalories()<<" Calories/day."<< endl;

            if((cal_ob->getCalorie()-food_obj->foodCalories())==0){
                outfile << "You are taking Equal amount, which is great." << endl;
            }else if((cal_ob->getCalorie()-food_obj->foodCalories())>0){
                outfile << "You are taking less amount, so you should take more." << endl;
            }else{
                outfile << "You are taking more then your limited amount, so you take it " <<cal_ob->getCalorie()<<" Calories/day."<< endl;
            }

            outfile
            << "Food intake evaluation: " << endl
            << "\tDaily consumption amount of Fats, oil and Sweets is: " << food_obj->getFats() << endl
            << "\tDaily consumption amount of Protein is: " << food_obj->getPortions() << endl
            << "\tDaily consumption amount of Dairy product is: " << food_obj->getDairy() << endl
            << "\tDaily consumption amount of Fruits and vegetables is: " << food_obj->getFruitVeg() << endl
            << "\tDaily consumption amount of Carbohydrates is: " << food_obj->getCarbs() << endl
            << "\tDaily consumption amount of Water per day is: " << food_obj->getWater() << endl
            << "\n\n\n********************************************************************\n"
            << "Take a Good care of your health and try to walk 30 minutes in a day.\n"
            << "                   Thank You, Please Come Again.";
            outfile.close();
        }else{cout << "failed to print file" << endl;}
    }
    ~Patient()
    {
        delete food_obj;
        delete cal_ob;
    }
};

int main(){
	FoodIntake food_obj;
	Calories cal_obj;
	Patient p1(&food_obj, &cal_obj);

	int choice = 0;
	cout << "Hello, welcome to the 'Food Intake Management Program'." << endl;
    p1.ReadAll();

    //calculate bmi and bmr
    p1.calculateBMI_BMR();

	do {
        std::system("cls");
		cout
        << "------------------------------------------" << endl
        << "                MAIN MENU                 " << endl
        << "------------------------------------------" << endl
		<< "Please choose what you would like to do." << endl
		<< "(1)     Input your food intake for the day " << endl
        << "(2)     Calculate your blood pressure and cholesterol" << endl
        << "(3)     Get feedback about your health" << endl
        << "(4)     Print food intake analysis report" << endl
		<< "(5)     exit the program" << endl
        << "------------------------------------------" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch(choice){

            case 1:
            std::system("cls");
            cout
            << "-----------------------------------------" << endl
            << "            OPTION 1 SELECTED            " << endl
            << "-----------------------------------------" << endl
            << "Here, you will input details about the food you've eaten throughout the day" << endl << endl;
            p1.readCalorie();
            p1.calcCalorie();
			p1.readFI();
            cout << endl;
            std::system("pause");
            std::system("cls");
            break;

            case 2:
            std::system("cls");
            cout
            << "-----------------------------------------" << endl
            << "            OPTION 2 SELECTED            " << endl
            << "-----------------------------------------" << endl;
            //this reads user inputs and calculates blood pressure
            p1.readChol();
            p1.readBP();
			p1.calcBP();
            cout << endl;
            std::system("pause");
            std::system("cls");
            break;

            case 3:
            std::system("cls");
            cout
            << "-----------------------------------------" << endl
            << "            OPTION 3 SELECTED            " << endl
            << "-----------------------------------------" << endl;
			//this displays the food recommendations, cholesterol levels,
			//blood pressure levels, bmi, and bmr
            p1.dispFI();
            cout << endl;
            p1.dispCalorie();
            cout << "But the amount of calories you are taking " << food_obj.foodCalories()<<" Calories/day."<< endl;

            if((p1.getCalorieAmount()-food_obj.foodCalories())==0){
                cout << "You are taking Equal amount, which is great." << endl;
            }else if((p1.getCalorieAmount()-food_obj.foodCalories())>0){
                cout << "You are taking less amount, so you should take more." << endl;
            }else{
                cout << "You are taking more then your limited amount, so you take it " <<p1.getCalorieAmount()<<" Calories/day."<< endl;
            }
            cout << endl;
            food_obj.displayBMI();
            cout << endl;
            food_obj.display();
            cout << endl;
            p1.dispBP();
            cout << endl;
            p1.dispChol();
            cout << endl;
            p1.getCalorieAmount();
            cout << endl;

            std::system("pause");
            std::system("cls");
            break;

            case 4:
            std::system("cls");
            cout
            << "-----------------------------------------" << endl
            << "            OPTION 4 SELECTED            " << endl
            << "-----------------------------------------" << endl;
            p1.printOutReport();
			cout << "Your food intake analysis report is ready. \nPlease check the text file.\n" << endl;

			std::system("pause");
            std::system("cls");
            break;

            case 5:
            std::system("cls");
            cout
            << "-----------------------------------------" << endl
            << "            OPTION 5 SELECTED            " << endl
            << "-----------------------------------------" << endl;
			cout
            << "            Exiting program" << endl;
			exit;
            break;

            default:
			cout << "\nInvalid choice, please try again" << endl;
            break;
        }
	} while (choice != 5 || choice > 5);

    cout
    <<"\n----------------------------------------------\n"
    << "       Thank You for running our program.\n"
    << "           Stay safe and healthy. " << endl;

    system("pause");
    return 0;
}
