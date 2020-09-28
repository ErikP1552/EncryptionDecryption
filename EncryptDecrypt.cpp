// Author : Erik Pantoja
// Partner Huy Tran
// Serial number : 32
// Group Number:  6
// Due Date : Monday 25 Feb 2019
// Programming Assignment Number 2
// Spring 2019 - CS 3358 - 253
// Instructor: Husain Gholoom.
// Program to encrypt or decrypt a string

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <sstream>

using namespace std;

// Function Declarations
void encrypt(int);
void decrypt(int);
void welcome();
string choose();
int numberKey();
void toLower(string& makeLower);
void goAgain();

// No Global Variables

int main()
{
    welcome();
    string choiceNum = choose();
    
    if(choiceNum == "encrypt")
    {
        
        int keyNum = numberKey(); // integer value to pass to next function
        // 1-36
        encrypt(keyNum);
        choiceNum.clear();
        goAgain();}
    
    else if(choiceNum == "decrypt"){
    
        int keyNum = numberKey(); // integer value to pass to next function
        // 1-36
        decrypt(keyNum);
        choiceNum.clear();;
        goAgain();}
    else if(choiceNum == "exit"){
        exit(0);}
    
    else{
        choiceNum.clear();
            cout << "\nInvalid Input !!!\n";
    }
    
    goAgain();
    return 0;
}




/* Function that displays the welcome message to the program
 *
 */
void welcome(){
    cout << " Welcome to cryptography "<<endl;
    cout << endl <<endl;
}



/* Function that lets the user choose what functions they want to use
 *@returns userInput
 */
string choose(){
    try {
        string userInput;
    cout << " Do you wish to encrypt or decrypt a message? (encrypt, decrypt, exit)"<<endl;
        cin >> userInput; // integer value for user input
                          // encrypt, decrypt, or exit
    
    while (userInput != "encrypt" && userInput != "decrypt" && userInput != "exit")
    {
        cout << "You have entered an invalid choice. \n";
        cout << "Please try again. \n";
        cout << "Enter a proper option: ";
        cin.clear();
        cin >> userInput;
    }
    return userInput; // integer value for user input
                      // encrypt, decrypt, or exit
    }
        catch (exception e){
            cout << "choose function could not be run";
            return NULL;
        }
}
    



/* Function that accepts a key to use to base the program after
 *@returns keyNum
 */
int numberKey(){
    try{
    int keyNum;     // integer value for the input key
                    // 1-36
        
    cout << "Please enter a number key to use to encrypt/decrypt ";
    cin >> keyNum;
    
    while (keyNum > 36 || keyNum < 0 || (!cin << keyNum))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "You have entered an invalid number. \n";
        cout << "Enter a proper number key: (1-36)"<<endl;
        cin >> keyNum;
    }
    return keyNum;
  
    } catch (exception e){
        cout << "The number key function could not be run";
        return NULL;
    }
    
}




/* Function that encrypts a string based off the user inputted key
 *@param keyNum
 */
void encrypt(int keyNum)
{
    try{
   
    vector<string> library = {"a","b", "c", "d", "e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z", "0","1","2","3","4","5","6","7","8","9"};
        string wordStorage; // String to store the lowercase letters
                            // Any message can be put into it
        
      cout << "Please enter a message to be encrypted: ";
        string getMessage;  // String value for message
                            // Any message
        
    cin.get();
    getline(cin, getMessage);
  cout << endl << "Your translated text is: ";
    
    for(int i=0; i<getMessage.size() ; i++)
    {
       wordStorage = getMessage[i];
       toLower(wordStorage);
        //cout << word; debug
        for(int h = 0; h < library.size(); h++){
            if (library[h] == wordStorage && (( h+keyNum ) < 36)){
               int y = h + keyNum;
            cout << library[y];
            }
            else if (library[h] == wordStorage && ((h + keyNum) > 36 )){
                int o = h + keyNum - 36;
                cout << library[o];}
        
            else if (library[h] != wordStorage && h < 1){
                if (find(library.begin(), library.end(), wordStorage) != library.end())
                    cout << "";
                else
                    cout << wordStorage;
            }
            }
    }
    cout << endl <<endl;
    }
        catch(exception e){
            cout << " The Encrypt Function could not be run";
        }
    }



/* Function that decrypts a message by moving it backwards by the input key
 *@param keyNum
 */
void decrypt(int keyNum)
{
    try{
    vector<string> library = {"a","b", "c", "d", "e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z", "0","1","2","3","4","5","6","7","8","9"};
   
    string getMessage,wordStorage;
    cout << "Please enter a message to be decrypted: ";
    string inputMessage;
    cin.get();
    getline(cin, getMessage);
    cout << endl << "Your translated text is:";
    
    for(int i=0; i < getMessage.size(); i++)
    {
        wordStorage = getMessage[i];
        toLower(wordStorage); 
        
        for(int h=0; h < library.size(); h++){
            if (library[h] == wordStorage && (( h - keyNum) < 36)){
                int y = h - keyNum; //int value displays value if its listed in the vector
                cout << library[y];
            }
            
            else if (library[h] == wordStorage && (( h - keyNum ) > 36 )){
                int o = h - keyNum + 36; // int value displays value if listed past the limits for the array
                cout << library[o];
            }
           
            else if (library[h] != wordStorage && h < 1){
                if (find(library.begin(), library.end(), wordStorage) != library.end())
                    cout << "";
                else
                    cout << wordStorage; //Displays char if it is not in the array
            }
        }
    }
  cout << endl;
        
    } catch (exception e){
        cout << "The Decrypt Function could not be run";
    }
}


/* Function that converts string to lowercase
*@param string& makeLower
*/
void toLower(string& makeLower)
{
    try{
    for(int i=0; i<makeLower.length(); i++) //start from 0 and go up till the length of the string (Increment by 1 loop)
    {
        makeLower[i] = tolower(makeLower[i]);//getting the character of the string and using the pre-made function tolower from the cctype library
    }
    } catch (exception e){
        cout << "To Lower function could not be implemented";
    }
}


/* Function that asks if the users would like to make another choice
 * Function wil run the program again if selected
 */
void goAgain(){
    
    try{
    
    string choiceNumb = choose();
    if(choiceNumb == "encrypt")
    {
        int keyNum = numberKey();
        encrypt(keyNum);
        goAgain();}
    
    else if(choiceNumb == "decrypt"){
        
        int keyNum = numberKey();
        decrypt(keyNum);
        goAgain();}
    else if(choiceNumb == "exit"){
        exit(0);}
    else{
        
        cout << "\nInvalid Input !!!\n";
    }
    goAgain();

} catch (exception e){
    cout << " The go again function could not be run";
}
}
