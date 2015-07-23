#ifndef ASSIGNMENT1
#define ASSIGNMENT1
void Get_Data(int&,int&,int&);//get Data
void Up_Down_Left_Right(int &); //1.The direction of the arrow is selected by clicking a radio button. So, there has to be four radio buttons, one for each direction.
//2.The default direction is up. So, your application should make that selection once started.
void Get_Positive_Odd_Int(int &);//3.The head width, shaft length, and shaft width are all positive odd integers. If an even number is specified, the next smaller odd number is used.
void Check_Hw(int &);//4.The head width must be greater than or equal to 5 and less than or equal to 25.
void Check_Hw_Sw(int &, int&);//5. The width of the head is longer than the width of the shaft.
void Check_Sl_Sw(int &, int&);//6.The length of the shaft is at least as long as the width of the shaft.
void Check_Close(int &);//7. She does not want to exit the application by accident. So, she wants the application to verify with her as it is closing
void Output(int,int,int,int);//2. first is up.
void shaft(int,int,int,int);//up = down , left = right
void Word(int);//display word
#endif