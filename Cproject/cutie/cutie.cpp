#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;
int food = 0, medicine = 0, board_game = 0, mask = 0, map = 0, money = 500;
int health1 = 10, health2 = 10, hunger1 = 2, hunger2 = 2, sanity1 = 4, sanity2 = 4; 
bool sick1 = false, sick2 = false;
int store();
int resourceManage();
int ending(int ending_number);
int status();
int randEventIn();
int randEventOut(int player);
int week();



int main()
{
string start;
cout << "The Story so far ..." << endl;
cout << "Hello, this is the story of Perone and Twoson." <<endl;
cout << "Long ago, everyone lived together in harmony." <<endl;
cout << "Then, everything changed when Covid-19 attacked."<< endl;
cout << "Only the Quartine Master, master of all survival elements, could stop them." << endl;
cout << "But when the world needed him most, he vanished." << endl;
cout << "One day later, some people believe life will not be the same and the cycle will never be broken." << endl;
cout << "But they haven't lost hope, they believe a vaccine will save the world." << endl; 
cout << "___________________________________________________________________________________" << endl;
cout << "Your objective: Survive to week 30 and escape quarantine without losing your lives." << endl;
cout << "Type start to continue: "; 
cin >> start;
if (start == "start")
{
    cout << endl;
    store();
    week();  
}
else
{
    cout << endl;
    store();
    week();
}

return 0;
}

int week()
{
    int week = 0;
    string goOut;
    int choice = 0;
    bool win = false;
    while(!win)
    {
        if(week == 0)
        {
            cout << "Week: " << week << endl;
            cout << "You are now sheltered inside your house." << endl;
        }
        else if(week > 0 && week < 30)
        {
            cout << "Week: " << week << endl;
            status();
            randEventIn();
            resourceManage();
            if (map > 0 && mask > 0)
            {
                cout << "Since you have both a mask and a map, you are somewhat safe to explore the outside." << endl;
                cout << "Will you decide to go outside? (type y for yes and type n for no)" << endl;
                cin >> goOut;
                if (goOut == "y" || goOut == "yes")
                {
                    cout << "Now please choose your character to go. (type 1 for Perone and type 2 for Twoson)" << endl;
                    cin >> choice;
                    randEventOut(choice);
                }
                else if (goOut == "n" || goOut == "no")
                {
                    cout << "Move on to next week"<< endl;
                }
            }
        }
        else if(week == 30)
        {
            win = true;
            ending(2);
        }
        week++;
    }
    return 0;
}

int resourceManage()
{
    string supply1;
    string supply2;
    string supply_one;
    string supply_two;
    bool notQuitting;
    int i = 0;
    cout << "This is the opportunity to give Perone or Twoson supplies they need" << endl;
    cout << "Do you want to give Perone or Twoson any supplies? y/n" << endl;
    cin >> supply1;
    if(supply1 == "y" || supply1 == "yes")
    {
        notQuitting = true;
    }
    else
    {
        notQuitting = false;
    }
    while(notQuitting)
    {
        cout << "What supply do you wanna give Perone? (food, medicine, or boardgame?) or type anything else to move on or type quit to exit" << endl;
        while (i == 0){
            cin >> supply_one;
            if(supply_one == "food")
            {
                cout << "You gave 1 food to Perone." << endl;
                food = food - 1;
                if(hunger1 == 2)
                {
                    hunger1 = hunger1;
                }
                else if(hunger1 == 0 || hunger1 == 1){
                    hunger1++;
                }
            }
            else if(supply_one == "medicine")
            {
                cout << "You gave 1 medicine to Perone." << endl;
                medicine = medicine - 1;
                if (health1 >= 9)
                {
                    health1 = 10;
                    sick1 = false;
                }
                else if(health1 <8)
                {
                    health1 = health1 + 2;
                    sick1 = false;
                }
            }
            else if(supply_one == "boardgame")
            {
                cout << "You gave 1 boardgame to Perone" << endl;
                board_game = board_game - 1;
                if (sanity1 >= 2)
                {
                    sanity1 = 4; 
                }
                else if(sanity1 < 2)
                {
                    sanity1 = sanity1 + 2;
                }
            }
            else if(supply_one == "quit")
            {
                return 0;
            }
            else
            {
                cout << "You decide not to give Perone any supplies" << endl;
                i = 1;
            }
        }
        cout << "What supply do you wanna give Twoson? (food, medicine, or boardgame?) or type anything else to quit to exit" << endl;
        while (i == 1){
            cin >> supply_two;
            if(supply_two == "food")
            {
                cout << "You gave 1 food to Twoson." << endl;
                food = food - 1;
                if(hunger2 == 2)
                {
                    hunger2 = hunger2;
                }
                else if(hunger2 == 0 || hunger2 == 1){
                    hunger2++;
                }
            }
            else if(supply_two == "medicine")
            {
                cout << "You gave 1 medicine to Twoson." << endl;
                medicine = medicine - 1;
                if (health2 >= 9)
                {
                    health2 = 10;
                    sick2 = false;
                }
                else if(health2 < 8)
                {
                    health2 = health2 + 2;
                    sick2 = false;
                }
            }
            else if(supply_two == "boardgame")
            {
                cout << "You gave 1 boardgame to Twoson" << endl;
                board_game = board_game - 1;
                if (sanity2 >= 2)
                {
                    sanity2 = 4; 
                }
                else if(sanity2 < 2)
                {
                    sanity2 = sanity2 + 2;
                }
            }
            else if(supply_two == "quit")
            {
                return 0;
            }
            else
            {
                cout << "You decide not to give Twoson any supplies" << endl;
                return 0;
            }
        }
    }
    return 0;
    
}

int randEventIn()
{
    int event_number;
    string robber_choice;
    string bored_choice;
    string merchant_choice;
    int item_choice;
    int survivability;
    int sick_chance;
    string wifi_choice;
    string medicine_choice;
    srand((time(0)*30));
    event_number = (rand() % 2001) + 1;
    cout << event_number << endl; // NOTE

    // Event 1
    if ((event_number <= 200) && (event_number >= 1))
    {
        cout << "A mysterious person comes to Perone and Twoson's house. " << endl;
        cout << "They do not know whether they are armed or not, but the two hear someone talk." << endl;
        cout << "He/she says give me money or else" << endl;
        cout << "What will you do? (type y to give in to demand or type n to refuse)" << endl;
        cin >> robber_choice;
        if(robber_choice == "y" || robber_choice == "yes")
        {
            if((money - 50) < 0)
            {
                cout <<"The duo do not have enough money to give to the mysterious person" << endl;
                cout << "......" << endl;
                survivability = ((rand() % 10) +1);
                if((survivability >= 1) && (survivability <= 3))
                {
                    cout << "The robber decided to attack them and they died." << endl;
                    ending(1);
                    return 0;
                }
                else if((survivability >=4) && (survivability <=10))
                {
                    cout <<"They fought off the robber. Good job." << endl;
                }    
            }
            cout << "They gave the mysterious person 50 dollars." << endl;
            money = money - 50;
        }
        else if(robber_choice == "n" || robber_choice == "no")
        {
            cout << "They decided to refuse their demands" << endl;
            cout << "....." << endl;
            survivability = ((rand() % 10) +1);
                if(survivability >= 1 && survivability <= 3)
                {
                    cout << "The robber decided to attack them and they died." << endl;
                    ending(1);
                    return 0;
                }
                else if(survivability >=4 && survivability <=10)
                {
                    cout <<"They fought off the robber. Good job." << endl;
                }
        }    
    }
    // Event 2
    else if ((event_number <= 400) && (event_number >= 201)) 
    {
        sick_chance = (rand() % 2) + 1;
        if (sick_chance == 1)
        {
            sick1 = true;
        }
        else if (sick_chance == 2)
        {
            sick2 = true;
        }
        if (sick1)
        {
            cout << "Perone gets sick" << endl;
            if (medicine > 0)
            {
                cout << "You have medicine to give." << endl;
                cout << "If you give them medicine they won't be sick, but if you don't they will lose one health each week." << endl;
                cout << "Will you give them medicine? (type y for yes and type n for no)" << endl;
                cin >> medicine_choice;
                if (medicine_choice == "y" || medicine_choice == "yes")
                {
                    sick1 = false;
                    cout << "Perone is now healthy!" << endl;
                    if (health1 == 10)
                    {
                        health1 = health1;
                        medicine = medicine - 1;
                    }
                    else if (health1 == 9)
                    {
                        health1 = health1 + 1;
                        medicine = medicine - 1;
                        cout << "Perone gained 1 health for taking the medicine." << endl;
                    }
                    else 
                    {
                        health1 = health1 + 2;
                        medicine = medicine - 1;
                        cout << "Perone gained 2 health for taking the medicine" << endl;
                    }
                }
                else if (medicine_choice == "n" || medicine_choice == "no")
                {
                    health1 = health1 - 1;
                    cout << "Perone is still sick and will lose 1 health!" << endl;
                }  
            }
            else if (medicine == 0)
            {
                health1 = health1 - 1;
                cout << "Perone is sick and will lose 1 health!" << endl;
            }
            if (health1 <= 0) 
            {
                cout << "Perone is dead!" << endl;
                ending(1);
            }
        }
        else if (sick2)
        {
            cout << "Twoson gets sick" << endl;
            if (medicine > 0)
            {
                cout << "You have medicine to give." << endl;
                cout << "If you give them medicine they won't be sick, but if you don't they will lose one health each week." << endl;
                cout << "Will you give them medicine? (type y for yes and type n for no)" << endl;
                cin >> medicine_choice;
                if (medicine_choice == "y" || medicine_choice == "yes")
                {
                    sick1 = false;
                    cout << "Twoson is now healthy!" << endl;
                    if (health2 == 10)
                    {
                        health2 = health2;
                        medicine = medicine - 1;
                    }
                    else if (health2 == 9)
                    {
                        health2 = health2 + 1;
                        medicine = medicine - 1;
                        cout << "Twoson gained 1 health for taking the medicine." << endl;
                    }
                    else 
                    {
                        health2 = health2 + 2;
                        medicine = medicine - 1;
                        cout << "Twoson gained 2 health for taking the medicine" << endl;
                    }
                }
                else if (medicine_choice == "n" || medicine_choice == "no")
                {
                    health2 = health2 - 1;
                    cout << "Twoson is still sick and will lose 1 health!" << endl;
                }  
            }
            else if (medicine == 0)
            {
                health1 = health1 - 1;
                cout << "Twoson is sick and will lose 1 health!" << endl;
            }
            if (health2 <= 0) 
            {
                cout << "Twoson is dead!" << endl;
                ending(1);
            }
        }
    }
    // Event 3
    else if((event_number <= 600) && (event_number >= 401))
    {
        if(food > 0)
        {
            cout << "Your food gets moldy. You lose one food." << endl;
            food = food - 1;
        }
        else if(food == 0)
        {
            cout <<"Your food would've been moldy, but you have no food left!" << endl;
        }
    }
    // Event 4
    else if((event_number <= 700) && (event_number >= 601))
    {
        cout <<"Perone gets bored." << endl;
        cout << "Will you use a board game to entertain Perone? y/n" << endl;
        cin >> bored_choice;
        if(board_game >= 1)
        {
            if(bored_choice == "y" || bored_choice == "yes")
            {
                cout << "Perone is no longer bored." << endl;
                board_game = board_game - 1;
                if(sanity1 >=3)
                {
                    sanity1 = 4;
                }
                else if(sanity1 < 3)
                {
                    sanity1++;
                }
            }
            else if(bored_choice == "n" || bored_choice == "no")
            {
                cout << "Perone is still bored and decreases in sanity." << endl;
                sanity1 = sanity1 - 2;
                if (sanity1 <= 0) 
                {
                    sanity1 = 0;
                }
            }
        }
        else if(board_game == 0)
        {
            cout <<"You have no board games and thus Perone is still bored and decreases in sanity." << endl;
            sanity1 = sanity1 - 2;
            if (sanity1 <= 0) 
            {
                sanity1 = 0;
            }
        }
        
    }
    // Event 4.5
    else if((event_number <= 800) && (event_number >=701))
    {
        cout <<"Twoson gets bored." << endl;
        cout << "Will you use a board game to entertain Twoson? y/n" << endl;
        cin >> bored_choice;
        if(board_game >= 1)
        {
            if(bored_choice == "y" || bored_choice == "yes")
            {
                cout << "Twoson is no longer bored." << endl;
                board_game = board_game - 1;
                if(sanity2 >= 3)
                {
                    sanity2 = 4;
                }
                else if(sanity2 < 3)
                {
                    sanity2++;
                }
            }
            else if(bored_choice == "n" || bored_choice == "no")
            {
                cout << "Twoson is still bored and decreases in sanity." << endl;
                if(sanity2 >= 2)
                {
                    sanity2 = sanity2 - 2;
                }
                else if(sanity2 < 2)
                {
                    sanity2 = 0;
                }
            }
        }
        else if(board_game == 0)
        {
            cout <<"You have no board games and thus Twoson is still bored and decreases in sanity." << endl;
            if(sanity2 >= 2)
            {
                sanity2 = sanity2 - 2;
            }
            else if(sanity2 < 2)
            {
                sanity2 = 0;
            }
        }
    }
    // Event 5
    else if((event_number <=1000) && (event_number >=801))
    {
        if(mask > 0)
        {
            cout << "A mask suddenly breaks. You lose one mask." << endl;
            mask = mask - 1;
        }
        else if(mask == 0)
        {
            cout <<"Your mask would've broken, but you have no masks left!" << endl;
        }
    }
    // Event 6
    else if((event_number <= 1200) && (event_number >= 1001))
    {
        cout << "A mysterious person comes to your door" << endl;
        cout << "The person says they are a merchant and are willing to exchange an item for $10" << endl;
        cout << "Will you do it? y/n" <<endl;
        cin >> merchant_choice;
        if((money-10)>=0)
        {
            if(merchant_choice == "y" || merchant_choice == "yes")
            {
                item_choice = ((rand() % 5) + 1);
                if(item_choice == 1)
                {
                    cout << "You gave the $10 and got 1 medicine!" << endl;
                    money = money - 10;
                    medicine++;
                }
                else if(item_choice == 2)
                {
                    cout << "You gave the $10 and got 1 food!" << endl;
                    money = money - 10;
                    food++;
                }
                else if(item_choice == 3)
                {
                    cout << "You gave the $10 and got 1 board game!" << endl;
                    money = money - 10;
                    board_game++;
                }
                else if(item_choice == 4)
                {
                    cout << "You gave the $10 and got 1 mask!" << endl;
                    money = money - 10;
                    mask++;
                }
                else if(item_choice == 5)
                {
                    cout << "You gave the $10 and got 1 map!" << endl;
                    map = map - 10;
                    mask++;
                }
            }
            else if(merchant_choice == "n" || merchant_choice == "no")
            {
                cout << "The merchant says understandable have a nice day." << endl;
            }
        }
        else if((money-10) < 0)
        {
            cout << "You cannot afford to do this exchange, but the merchant gives you $10 because he/she feels bad for you." << endl;
            money = money + 10;
        }
    }
    // Event 7
    else if(event_number <= 1400 && event_number >= 1201)
    {
        cout << "A friendly person comes to your door and gives you all the items you could ever want." << endl;
        cout << "You get an increase of 1 to all your items." << endl;
        medicine++;
        food++;
        board_game++;
        mask++;
        map++;
    }
    // Event 8
    else if(event_number <= 1600 && event_number >= 1401)
    {
        cout << "It's someone's birthday and everyone liked that." << endl;
        cout << "Everyone's sanity is maxed out" << endl;
        sanity1 = 4;
        sanity2 = 4;
    }
    // Event 9
    else if(event_number <= 1800 && event_number >= 1601)
    {
        cout << "Everyone decides to work out and get gains" << endl;
        cout << "Everyone's health and sanity is increased by 1!" << endl;
        if (sanity1 == 4)
        {
            sanity1 = sanity1;
        }
        else if (sanity1 <= 3)
        {
            sanity1++;
        }
        if (sanity2 == 4)
        {
            sanity2 = sanity2;
        }
        else if (sanity2 <= 3)
        {
            sanity2++;
        }
        if (health1 == 10)
        {
            health1 = health1;
        }
        else if (health1 <= 9);
        {
            health1++;
        }
        if (health2 == 10)
        {
            health2 = health2;
        }
        else if (health2 <= 9);
        {
            health2++;;
        }
    }
    // Event 10
    else if(event_number <= 2000 && event_number >= 1801)
    {
        cout << "The wifi has gone out." << endl;
        cout << "Unless you both play board games, you will both be bored." << endl;
        cout << "Will you play a board game?" << endl;
        cin >> wifi_choice;
        if(board_game >= 1)
        {
            if(wifi_choice == "y" || wifi_choice == "yes")
            {
                cout << "You both decide to play a board game and have gained a little bit of sanity." << endl;
                board_game = board_game - 1;
                if(sanity1>=3)
                {
                    sanity1 = 4;
                }
                else if(sanity1 < 3)
                {
                    sanity1++;
                }
                if(sanity2>=3)
                {
                    sanity2 = 4;
                }
                else if(sanity2 < 3)
                {
                    sanity2++;
                }
            }
            if(wifi_choice == "n" || wifi_choice == "no")
            {
                cout << "You decide to not play a board game and your sanity has decreased." << endl;
                if(sanity1<=0)
                {
                    sanity1 = 0;
                }
                else if(sanity1 > 0)
                {
                    sanity1--;
                }
                if(sanity2<=0)
                {
                    sanity2 = 0;
                }
                else if(sanity2 > 0)
                {
                    sanity2--;
                }   
            }
        }
        else if (board_game == 0) 
        {
            cout << "You have no board games to play so your sanity has decreased." << endl;
            if(sanity1<=0)
            {
                sanity1 = 0;
            }
            else if(sanity1 > 0)
            {
                sanity1--;
            }
            if(sanity2<=0)
            {
                sanity2 = 0;
            }
            else if(sanity2 > 0)
            {
                sanity2--;
            }   
        }
    }
    // Event 11
    else if(event_number == 2001)
    {
        ending(3);
        return 0;

    }
    return 0;
}



int randEventOut(int player)
{
    int event_number;
    srand((time(0)*4));
    event_number = (rand() % 101) + 1;
    if (player == 1)
    {
        if(event_number>=1 && event_number <=20)
        {
            cout << "Perone decided to hang out with friends" << endl;
            cout << "Perone gained a bit of sanity." << endl;
            if(sanity1 <=2)
            {
                sanity1 = sanity1 + 2;
            }
            else if(sanity1 == 3 || sanity1 == 4)
            {
                sanity1 = 4;
            }
        }
        else if(event_number >=21 && event_number <= 40)
        {
            cout << "Perone decided to eat a restaurant." << endl;
            cout << "Perone lost 1 hunger." << endl;
            if(hunger1 ==2)
            {
                hunger1 = hunger1;
            }
            else if(hunger1 == 0 || hunger1 == 1)
            {
                hunger1++;
            }
        }
        else if(event_number >=41 && event_number <=60)
        {
            cout << "Perone decided to go to a doctor." << endl;
            cout << "Perone gained 2 health" << endl;
            if(health1 >= 8 && health1 <= 10)
            {
                health1 = 10;
            }
            else if(health1 <=7)
            {
                health1 = health1 + 3;
            }
        }
        else if(event_number >= 61 && event_number <= 80)
        {
            cout << "Perone went out and got a bunch of useful items!" << endl;
            medicine++;
            food++;
            board_game++;
            mask++;
            map++;
        }
        else if(event_number >= 81 && event_number <=100)
        {
            cout << "Perone was minding his own business walking out." << endl;
            cout << "BUT there was a robber!" << endl;
            if((money-50)<0)
            {
                cout << "Perone lost 2 health." << endl;
                if(health1>2)
                {
                health1 = health1 - 2;
                }
                else
                {
                    cout << "Perone died." << endl; // NOT SURE WHAT TO DO WHEN ONE DIES
                    ending(1);
                }
            }
            else if((money-50)>=0)
            {
                cout << "Perone lost 2 health and 50 dollars." << endl;
                if(health1>2)
                {
                health1 = health1 - 2;
                money = money - 50;
                }
                else
                {
                    cout << "Perone died." << endl; // NOT SURE WHAT TO DO WHEN ONE DIES
                    money = money - 50;
                    ending(1);
                }
            }
        }
        else if(event_number == 101)
        {
            cout << "Oh no! Perone went out and got covid." << endl;
            cout << "Perone died." << endl; //Not sure what to do when Perone dies
            ending(1);            
        }
    }
    else if (player == 2)
    {
        if(event_number>=1 && event_number <=20)
        {
            cout << "Twoson decided to hang out with friends" << endl;
            cout << "Twoson gained a bit of sanity." <<endl;
            if(sanity2 <=2)
            {
                sanity2 = sanity2 + 2;
            }
            else if(sanity2 == 3 || sanity2 == 4)
            {
                sanity2 = 4;
            }
        }
        else if(event_number >=21 && event_number <= 40)
        {
            cout << "Twoson decided to eat a restaurant." << endl;
            cout << "Twoson lost 1 hunger." << endl;
            if(hunger2 ==2)
            {
                hunger2 = hunger2;
            }
            else if(hunger2 == 0 || hunger2 == 1)
            {
                hunger2++;
            }
        }
        else if(event_number >=41 && event_number <=60)
        {
            cout << "Twoson decided to go to a doctor." << endl;
            cout << "Twoson gained 2 health" << endl;
            if(health2 >= 8 && health2 <= 10)
            {
                health2 = 10;
            }
            else if(health2 <=7)
            {
                health2 = health2 + 3;
            }
        }
        else if(event_number >= 61 && event_number <= 80)
        {
            cout << "Twoson went out and got a bunch of useful items!" << endl;
            medicine++;
            food++;
            board_game++;
            mask++;
            map++;
        }
        else if(event_number >= 81 && event_number <=100)
        {
            cout << "Twoson was minding his own business walking out." << endl;
            cout << "BUT there was a robber!" << endl;
            if((money-50)<0)
            {
                cout << "Twoson lost 2 health." << endl;
                if(health2>2)
                {
                health2 = health2 - 2;
                }
                else
                {
                    cout << "Perone died." << endl; // NOT SURE WHAT TO DO WHEN ONE DIES
                    ending(1);
                }
            }
            else if((money-50)>=0)
            {
                cout << "Perone lost 2 health and 50 dollars." << endl;
                if(health2>2)
                {
                health2 = health2 - 2;
                money = money - 50;
                }
                else
                {
                    cout << "Perone died." << endl; // NOT SURE WHAT TO DO WHEN ONE DIES
                    money = money - 50;
                    ending(1);
                }
            }
            

        }
        else if(event_number == 101)
        {
            cout << "Oh no! Perone went out and got covid." << endl;
            cout << "Perone died." << endl; //not sure what to do when dead
            ending(1);          
        }
    }
    return 0;
}


int status() 
{
    cout << "Status of Perone and Twoson: " << endl;
    cout << "Max HP = 10, Max Hunger = 2, Max Sanity = 4" << endl;
    cout << "Perone: " << health1 << " HP, " << hunger1 << " Hunger, " << sanity1 << " Sanity, " << "Sick: " << sick1 << endl;
    cout << "Twoson: " << health2 << " HP, " << hunger2 << " Hunger, " << sanity2<< " Sanity, " << "Sick: " << sick2 << endl;
    cout << medicine << " medicine " << food << " food " << mask << " mask(s) " << board_game << " board game(s) " << map << " map(s)" << endl;
    cout << "Money Balance: " << money << endl;
    if (sick1 == true)
    {
        cout << "Since Perone is sick, they will lose 1 health this week." << endl;
        health1 = health1 - 2;
        if (health1 <= 0) 
        {
            cout << "Perone is dead!" << endl;
            ending(1);
        }
    }
    else if (sick2 == true)
    {
        cout << "Since Twoson is sick, they will lose 1 health this week." << endl;
        health2 = health2 - 2;
        if (health2 <= 0) 
        {
            cout << "Twoson is dead!" << endl;
            ending(1);
        }
    }
    if(hunger1 == 0)
    {
        hunger1 = 0; 
    }
    else if(hunger1 > 0)
    {
        hunger1 = hunger1 - 1;
    }
    if(hunger2 == 0)
    {
        hunger2 = 0; 
    }
    else if(hunger2 > 0)
    {
        hunger2 = hunger2 - 1;
    }
    if (hunger1 == 0)  
    {
        health1 = health1 -1;
        if (health1 <= 0)
        {
            cout << "Perone is dead!" << endl;
            ending(1);
        }
    }
    if (hunger2 == 0)  
    {
        health2 = health2 -1;
        if (health2 <= 0)
        {
            cout << "Twoson is dead!" << endl;
            ending(1);
        }
    }
    return 0;
}

int store()
{
    bool notQuit = true;
    string choice;
    int amount;
    unsigned int i;
    while(notQuit)
    {
        cout << "________________________________" << endl;
        cout << "         Welcome to shop        " << endl;
        cout << "________________________________" << endl;
        cout << "Type the number for the item    |" << endl;
        cout << "you want to buy:                |" << endl;
        cout << "1: Medicine - 20 dollars each   |" << " medicine owned: " << medicine << endl;
        cout << "2: Food - 10 dollars each       |" << " food owned: " << food << endl;
        cout << "3: Mask - 15 dollars each       |" << " masks owned: " << mask << endl;
        cout << "4: Board game - 10 dollars each |" << " board games owned: " << board_game << endl;
        cout << "5: Map - 15 dollars each        |" << " map owned: " << map << endl; 
        cout << "________________________________|" << endl;
        cout << "Money remaining: $"<< money << endl;     
        cout << "Type quit to exit shop"<< endl;
        cin >> choice;
        if(choice == "1")
        {
            cout << "Buy Medicine? y/n" << endl;
            cin >> choice;
            if(choice == "y" || choice == "yes")
            {
                cout << "How many?" << endl;
                cin >> amount;
                if((money-(amount * 20)) < 0){
                    cout <<"You cannot afford to buy " << amount << " medicine" << endl;
                } 
                else 
                {
                    money = money-(amount * 20);
                    medicine = medicine + amount;
                    cout << "Success! You bought " << amount << " medicine!" << endl;
                }
            }
            else
            {
                cout << "Back to shop" << endl;
            }
        }
        else if(choice == "2")
        {
            cout << "Buy Food? y/n" << endl;
            cin >> choice;
            if(choice == "y" || choice == "yes")
            {
                cout << "How many?" << endl;
                cin >> amount;
                if((money-(amount * 10)) < 0){
                    cout <<"You cannot afford to buy " << amount << " food" << endl;
                } 
                else 
                {
                    money = money-(amount * 10);
                    food = food + amount;
                    cout << "Success! You bought " << amount << " food!" << endl;
                }
            }
            else
            {
                cout << "Back to shop" << endl;
            }
        }
        else if(choice == "3")
        {
            cout << "Buy mask? y/n" << endl;
            cin >> choice;
            if(choice == "y" || choice == "yes")
            {
                cout << "How many?" << endl;
                cin >> amount;
                if((money-(amount * 15)) < 0){
                    cout <<"You cannot afford to buy " << amount << " mask(s)" << endl;
                } 
                else 
                {
                    money = money-(amount * 15);
                    mask  = mask + amount;
                    cout << "Success! You bought " << amount << " mask(s)!" << endl;
                }
            }
            else
            {
                cout << "Back to shop" << endl;
            }
        }
        else if(choice == "4")
        {
            cout << "Buy board games? y/n" << endl;
            cin >> choice;
            if(choice == "y" || choice == "yes")
            {
                cout << "How many?" << endl;
                cin >> amount;
                if((money-(amount * 10)) < 0){
                    cout <<"You cannot afford to buy " << amount << " board game(s)" << endl;
                } 
                else 
                {
                    money = money-(amount * 10);
                    board_game = board_game + amount;
                    cout << "Success! You bought " << amount << " board game(s)!" << endl;
                }
            }
            else
            {
                cout << "Back to shop" << endl;
            }
        }
        else if(choice == "5")
        {
            cout << "Buy Map? y/n" << endl;
            cin >> choice;
            if(choice == "y" || choice == "yes")
            {
                cout << "How many?" << endl;
                cin >> amount;
                if((money-(amount * 15)) < 0){
                    cout <<"You cannot afford to buy " << amount << " map(s)" << endl;
                } 
                else 
                {
                    money = money-(amount * 15);
                    map = map + amount;
                    cout << "Success! You bought " << amount << " map(s)!" << endl;
                }
            }
            else
            {
                cout << "Back to shop" << endl;
            }
        }
        else if(choice == "quit"){
            cout << "Are you sure you want to quit shop (you will not be able to return) y/n" << endl;
                cin >> choice;
                if(choice == "y" || choice == "yes")
                {
                    notQuit = false;
                }
                else
                {
                    cout << "Back to shop" << endl;
                }

        }
        else
        {
            cout << "Incorrect input" << endl;
        }
    }
    return 0;
}

int ending(int ending_number)
{
    if(ending_number == 1)
    {
        cout << "Unforunately, Perone or Twoson has passed away." << endl;
        cout << "Make sure to be more careful that both survive the epidemic." << endl;
        cout << "Game over." << endl;
        exit(0);
    }
    else if(ending_number == 2)
    {
        cout << "After 30 excruciating weeks of quarantine, Perone and Twoson emerge victorious from the epidemic." << endl;
        cout << "Congratuations for surviving and thanks for playing!" << endl;
        cout << "Game over." << endl;
        exit(0);
    }
    else if(ending_number == 3)
    {
        cout << "Mysterious people have come to your door." << endl;
        cout << "They say they have the secret vaccine to get rid of covid." << endl;
        cout << "Twoson and Perone both take the vaccine and it heals them!" << endl;
        cout << "You win! Ending: Secret" << endl;
        cout << "Game over." << endl;
        exit(0);
    }
    return 0;
}