#include<iostream>
#include<vector>
#include<math.h>
#include<string>
//max=32767
using namespace std;
int value[32768]={0};
vector<vector<int>> child;
vector<int> zero_val;
int output(int index){
	for(int level = 1; level < 6; level++){
		for(int blank = 0; blank < 5-level; blank++){
			cout << " ";
		}
		for(int a = 0; a < level; a++){
			if(index%2 == 1){
				cout << "X ";
			}
			else{
				cout << "* ";
			}
			index = index>>1;
		}
		cout << endl;
	}
	cout << endl;
}
void find_children(void){
	for(int a = 0; a < 32768-1; a++){
		vector<int> vec;
		int sigma = 0;
		for(int level = 1; level < 6; level++){
			sigma += level;
			for(int num = 1; num <= level; num++){
				int meow = sigma+num-level-1;
				if((a>>meow)%2 == 0){
					vec.push_back(a+pow(2,meow));
					if(vec.back()==32767){
						value[a] = 1;
					}
					if(level-num >= 1){
						if((a>>(meow+1))%2 == 0){
							vec.push_back(a+3*pow(2,meow));
							/*
							if(vec.back()==32767){
                                                		value[a] = -1;
                                        		}
							*/
							if(level-num >= 2){
								if((a>>(meow+2))%2 == 0){
									vec.push_back(a+7*pow(2,meow));
									/*
									if(vec.back()==32767){
                                                				value[a] = -1;
                                        				}
									*/
								}
							}
						}
					}
					if(level != 5){
						int meow2 = sigma + num - 1;
						if((a>>meow2)%2 == 0){
							vec.push_back(a + pow(2,meow) + pow(2,meow2));
							/*
							if(vec.back()==32767){
                                                                value[a] = -1;
                                                        }
							*/
							if(level != 4){
								int meow3 = meow2 + level + 1;
								if((a>>meow3)%2 == 0){
									vec.push_back(a + pow(2,meow) + pow(2,meow2) + pow(2,meow3));
									/*
									if(vec.back()==32767){
                                                                                value[a] = -1;
                                                                        }
									*/
								}
							}
						}
						meow2 += 1;
						if((a>>meow2)%2 == 0){
							vec.push_back(a + pow(2,meow) + pow(2,meow2));
							/*
							if(vec.back()==32767){
                                                        	value[a] = -1;
                                                        }
							*/
							if(level != 4){
								int meow3 = meow2 + level + 2;
								if((a>>meow3)%2 == 0){
									vec.push_back(a + pow(2,meow) + pow(2,meow2) + pow(2,meow3));
									/*
									if(vec.back()==32767){
                                                                                value[a] = -1;
                                                                        }
									*/
								}
							}
						}
					}
				}

			}
		}
		child.push_back(vec);
	}
}

void set_value(void){
	for(int index = 0 ; index < 32768; index++){
		/*
		int counter = 0;
		for(int a = 0; a < child[index].size(); a++){
			if(value[child[index][a]] == -1){
				counter++;
			}
		}
		if(counter == child[index].size()){
			value[index] = 1;
			//output(index);
		}
		*/
		if(value[index] == 0){
			zero_val.push_back(index);
		}
	}
	bool lock = true;
	while(lock){
		for(int index = 0; index < zero_val.size(); index++){
			int counter = 0;
			for(int a = 0; a < child[zero_val[index]].size(); a++){
				if(value[child[zero_val[index]][a]] == 1){
					value[zero_val[index]] = -1;
					zero_val.erase(zero_val.begin()+index);
					index--;
					counter = -1;
					break;
				}
				if(value[child[zero_val[index]][a]] == -1){
					counter++;
				}
			}
			if(counter == child[zero_val[index]].size()){
				value[zero_val[index]] = 1;
				//cout << zero_val[index] << " ";
				zero_val.erase(zero_val.begin()+index);
				index--;
			}
			/*if(zero_val.size() == 30000){
				cout << "3" << endl;
			}
			if(zero_val.size() == 20000){
                                cout << "2" << endl;
                        }
			if(zero_val.size() == 10000){
                                cout << "1" << endl;
                        }*/
		}
		if(zero_val.empty()){
			lock = false;
		}
		int perc = 100*(32768-zero_val.size())/32768;
		cout << '\r';
		cout << "Loading......" << perc << "%";
	}
	return;
}
int welcome(void){
	cout << "            Welcome to Nim!" << endl;
	while(true){
		cout << "Please choose to Go FIRST or Go SECOND"<< endl << "1) GO FIRST" << endl << "2) GO SECOND" << endl << "3) Player vs. Player" << endl << "4) GAME RULES" << endl << "5) Quit game" << endl << "Your Ans:";
		char a;
		cin >> a;
		if(a == '1'){
			return 1;
		}
		else if(a == '2'){
			return 2;
		}
		else if(a == '4'){
			cout << endl << endl;
			cout << "Rules:" << endl;
			cout << "Nim, or called triangular Nim, is a kind of board game." << endl;
			cout << "Two players (YOU and my AI) take turns removing stars on the board." << endl;
			cout << "Each time you can remove 1 to 3 stars in a row, and the stars you remove must stick together." << endl;
			cout << "Your goal is try NOT to be the one who removes the LAST star. Good luck!" << endl << endl;
			cout << "input index table:" << endl;
			cout << "    0" << endl;
			cout << "   1 2" << endl;
			cout << "  3 4 5" << endl;
			cout << " 6 7 8 9" << endl;
			cout << "A B C D E" << endl << endl << endl;
		}
		else if(a == '3'){
			return 3;
		}
		else if(a == '5'){
			return 5;
		}
		else{
			cout << "Please re-enter your answer!" << endl;
		}
	}
}
int AI_move(int index){
	srand(time(NULL));
	vector<int> vec;
	cout << endl << "My turn!" << endl << endl;
	for(int a = 0; a < child[index].size(); a++){
		if(value[child[index][a]] == 1){
			vec.push_back(child[index][a]);
		}
	}
	if(vec.empty()){
		//cout <<  "YOU'VE beat me?" << endl;
		int buf[2]={0};
		for(int b = 0; b < child[index].size(); b++){
			int counter = 0;
			for(int c = 0; c < child[child[index][b]].size(); c++){
				if(value[child[child[index][b]][c]] == -1){
					counter++;
				}
			}
			if(100*counter/child[child[index][b]].size() > buf[0]){
				buf[1] = b;
				buf[0] = 100*counter/child[child[index][b]].size();
			}
		}
		//cout << buf[0] << endl;
		output(child[index][buf[1]]);
		return child[index][buf[1]];
	}
	else{
		int a = rand() % vec.size();
		output(vec[a]);
		return vec[a];
	}
}
int input(int index){
	string a;
	cout << "Warning: Please DO NOT enter any 'space' in your answers! It may make the game crash or serious errors!"<< endl << "It's your turn! Please enter your choises(1~3 letters)(0~E)('S'to surrender):";
	cin >> a;
	cout << endl;
	if(a.size() == 1){
		int b;//-48
		b = a[0];
		//cout << b;
		if(b >= 48 && b <= 57){
			if((index>>(b-48))%2 == 0){
				index += pow(2,b-48);
				return index;
			}
		}
		else if(b >= 65 && b <= 69){
			if((index>>(b-55))%2 == 0){
				index += pow(2,b-55);
				return index;
			}
		}
		else if(a[0] == 'S'){
		return 32767;
		}
	}
	else if(a.size() == 2){
		int b[2];
		int index_ = index;
		b[0] = a[0];
		b[1] = a[1];
		int success = 0;
		if(b[0] >= 48 && b[0] <= 57){
                        if((index>>(b[0]-48))%2 == 0){
                                index += pow(2,b[0]-48);
				success += 1;
                        }
                }
                else if(b[0] >= 65 && b[0] <= 69){
                        if((index>>(b[0]-55))%2 == 0){
                                index += pow(2,b[0]-55);
                                success += 1;
                        }
                }
		if(b[1] >= 48 && b[1] <= 57){
                        if((index>>(b[1]-48))%2 == 0){
                                index += pow(2,b[1]-48);
                                success += 1;
                        }
                }
                else if(b[1] >= 65 && b[1] <= 69){
                        if((index>>(b[1]-55))%2 == 0){
                                index += pow(2,b[1]-55);
                                success += 1;
                        }
                }
		if(success == 2){
			for(int c = 0; c < child[index_].size(); c++){
				if(child[index_][c] == index){
					return index;
				}
			}
		}
		index = index_;
	}
	else if(a.size() == 3){
		int b[3];
                int index_ = index;
                b[0] = a[0];
                b[1] = a[1];
		b[2] = a[2];
                int success = 0;
		for(int d = 0 ; d < 3; d++){
			if(b[d] >= 48 && b[d] <= 57){
	                        if((index>>(b[d]-48))%2 == 0){
        	                        index += pow(2,b[d]-48);
	                                success += 1;
	                        }
	                }
	                else if(b[d] >= 65 && b[d] <= 69){ 
	                        if((index>>(b[d]-55))%2 == 0){
	                                index += pow(2,b[d]-55);
	                                success += 1;
	                        }
	                }
		}
                if(success == 3){
                        for(int c = 0; c < child[index_].size(); c++){
                                if(child[index_][c] == index){
                                        return index;
                                }
                        }
                }
                index = index_;
	}
	cout << "wrong input!" << endl;
	return input(index);
}
void game_start(void){
	int a = welcome();
	if(a == 1){
                bool alive = true;
                int board = 0;
		output(board);
                while(alive){
                        board = input(board);
			output(board);
                        if(board == 32767){
				cout << "YOU LOSE this Game!" << endl;
                                alive = false;
                        }
                        else{
                                board = AI_move(board);
                                if(board == 32767){
					cout << "Congratulations! You've won this game!" << endl;
                                        alive = false;
                                }
				else{
					cout << "And it's YOUR turn." << endl << endl;
				}
                        }
                }
        }
        else if(a == 2){
                bool alive = true;
                int board = 0;
                while(alive){
                        board = AI_move(board);
                        if(board == 32767){
				cout << "Congratulations! You've won this game!" << endl;
                                alive = false;
                        }
                        else{
				cout << "And it's YOUR turn." << endl << endl;
                                board = input(board);
				output(board);
                                if(board == 32767){
					cout << "YOU LOSE this Game!" << endl;
                                        alive = false;
                                }
                        }
                }
        }
	else if(a == 3){
		bool alive = true;
		int board = 0;
		output(board);
		while(alive){
			cout << "It's Player1's turn" << endl << endl;
			board = input(board);
			output(board);
			if(board == 32767){
				cout << "Player2 Wins!"<< endl;
				alive = false;
			}
			else{
				cout << "It's Player2's turn" << endl << endl;
				board = input(board);
				output(board);
				if(board == 32767){
					cout << "Player1 Wins!" << endl;
					alive = false;
				}
			}
		}
		
	}
	else{
		return;
	}
	while(true){
		cout << "New Game?(y/n):";
		char a;
		cin >> a;
		if(a == 'N' || a == 'n'){
			return;
		}
		else if(a == 'y' || a == 'Y'){
			game_start();
			return;
		}
		else{
			cout << "Wrong input! Please re-enter your answer!" << endl;
		}
	}
}
/*           1
           2   4
         8  16  32
       64 128 256 512
  1024 2048 4096 8192 16384
        *
       * *
      * * *
     * * * *
    * * * * *
*/
int main(){
	find_children();
	set_value();
	cout << '\r';
	game_start();
	/*
	int index;
	cin >> index;
	cout << value[index] << endl;
	output(index);
	for(int a = 0; a < child[index].size(); a++){
		cout << value[child[index][a]] << endl;
		output(child[index][a]);
	}
	*/
	cout << "See you next time!" << endl;
	return 0;
}
