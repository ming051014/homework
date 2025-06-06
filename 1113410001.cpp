#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
    srand(time(0));  // 初始化亂數種子

    int score = 0;   // 玩家初始分數
    string input;    // 玩家輸入
    int player;      // 玩家選擇的出拳數字

    cout << "請輸入 1（剪刀）、2（石頭）、3（布），或輸入 STOP 結束遊戲。" << endl;

    while (true) {
        cout << "\n你的選擇：";
        cin >> input;  // 讀取玩家輸入

        // 玩家想手動結束
        if (input == "STOP" || input == "stop") {
            cout << "結束遊戲，最終分數：" << score << endl;
            break;
        }

        // 判斷輸入是否合法，並轉成數字
        if (input == "1") player = 1;
        else if (input == "2") player = 2;
        else if (input == "3") player = 3;
        else {
            // 如果不是 1/2/3/STOP，就提示錯誤並結束
            cout << "輸入錯誤，遊戲結束。" << endl;
            break;
        }

        int computer = rand() % 3 + 1;  // 電腦出拳（1~3）
        string choices[4] = { "", "剪刀", "石頭", "布" };

        cout << "我：" << choices[player] << "，電腦：" << choices[computer] << endl;

        // 判斷勝負
        if (player == computer) {
            cout << "平手!(0)。" << endl;
        }
        else if ((player == 1 && computer == 3) ||
            (player == 2 && computer == 1) ||
            (player == 3 && computer == 2)) {
            cout << "贏！(+1)" << endl;
            score++;
        }
        else {
            cout << "輸！(-1)" << endl;
            score--;
        }

        cout << "目前分數：" << score << endl;

        // 勝利或失敗條件判斷
        if (score == 5) {
            cout << "🎉 恭喜你贏了整場遊戲！" << endl;
            break;
        }
        if (score == -1) {
            cout << "💀 你輸了整場遊戲。" << endl;
            break;
        }
    }

    return 0;  // 正常結束程式
}
