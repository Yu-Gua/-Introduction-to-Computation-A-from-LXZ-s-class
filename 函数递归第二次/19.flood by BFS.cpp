#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int lim = 210;
int length, width; // 地图高和宽
int endx, endy; // 指挥部
int map[lim][lim]; // 地形高度
int highestWaterLevel[lim][lim]; // 记录每个位置的最高水位
bool flag = false; // 标记目标是否可达

struct dot {
    int x;
    int y;
    int height;
};

dot waterPoint[lim*lim]; // 放水点情况数组
int movx[4] = {0, 1, 0, -1};
int movy[4] = {-1, 0, 1, 0};

bool isValid(int x, int y) {
    return x >= 0 && x < width && y >= 0 && y < length;
}

void bfs(int startX, int startY, int startHeight) {
    if(startHeight<highestWaterLevel[startY][startX])return;
    queue<dot> q;
    q.push({startX, startY, startHeight});
    highestWaterLevel[startY][startX]=startHeight;
    while (!q.empty()) {
        dot current = q.front();
        q.pop();

        // 如果当前位置是目标位置，则设置标志并返回
        if (current.x == endx && current.y == endy) {
            flag = true;
            return;
        }

        // 尝试四个方向移动
        for (int i = 0; i < 4; ++i) {
            int newX = current.x + movx[i];
            int newY = current.y + movy[i];

            if (isValid(newX, newY) && map[newY][newX] <= current.height &&
                highestWaterLevel[newY][newX] < current.height) {
                // 只有当新位置的高度小于等于当前水位，并且新位置的最高水位低于当前水位时才蔓延
                highestWaterLevel[newY][newX] = current.height;
                q.push({newX, newY, current.height});
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    for (int caseIndex = 0; caseIndex < N; ++caseIndex) {
        flag = false;

        cin >> length >> width;
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < width; ++j) {
                cin >> map[i][j];
                highestWaterLevel[i][j] = -1; // 初始化最高水位为-1表示未访问
            }
        }

        cin >> endy >> endx;
        --endy; --endx; // 调整为0索引

        int waterNum;
        cin >> waterNum;
        for (int i = 0; i < waterNum; ++i) {
            cin >> waterPoint[i].y >> waterPoint[i].x;
            --waterPoint[i].y; --waterPoint[i].x; // 调整为0索引
            waterPoint[i].height = map[waterPoint[i].y][waterPoint[i].x];
        }

        // 对每个放水点执行BFS
        for (int i = 0; i < waterNum; ++i) {
            bfs(waterPoint[i].x, waterPoint[i].y, waterPoint[i].height);
            if (flag) break;
        }
        
        if(flag)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}