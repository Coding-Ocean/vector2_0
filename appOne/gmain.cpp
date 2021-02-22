#include"libOne.h"
struct UNKO {
    float px = 0, py = 0, vx = 0, vy = 0;
};

void gmain() {
    window(1000,1000);
    int playerImg = loadImage("assets\\unkoPink.png");
    int enemyImg = loadImage("assets\\unkoWhite.png");
    struct UNKO p = { width/2,      height / 2 - 50 };
    struct UNKO e = { width/2+200,  height / 2 - 50 };
    float speed = 0;
    float maxSpeed = 10;
    float nearDist = 50;
    rectMode(CENTER);
    while (notQuit) {
        //プレイヤーの位置
        p.px = mouseX;
        p.py = mouseY;
        //enemyからplayerへのベクトル
        e.vx = p.px - e.px;
        e.vy = p.py - e.py;
        //距離
        float dist = sqrt(e.vx * e.vx + e.vy * e.vy);
        //ベクトルの長さを１にする
        if (dist != 0) {
            e.vx /= dist; 
            e.vy /= dist;
        }
        //近づいたらスピードを落とす
        if (dist > nearDist) {
            speed = maxSpeed;
        }
        else {
            speed = map(dist, 0, nearDist, 0, maxSpeed);
        }
        //最終的なベクトル
        e.vx *= speed;
        e.vy *= speed;
        //enemy移動
        e.px += e.vx;
        e.py += e.vy;

        /*
        //プレイヤーの位置
        p.px = mouseX;
        //enemyからplayerへのベクトル
        e.vx = p.px - e.px;
        //距離
        float dist = e.vx > 0 ? e.vx : -e.vx;
        //ベクトルの長さを１にする
        if (dist != 0){
            e.vx /= dist;
        }
        //近づいたらスピードを落とす
        if (dist > nearDist){
            speed = maxSpeed;
        }
        else{
            speed = map(dist, 0, nearDist, 0, maxSpeed);
        }
        //最終的なベクトル
        e.vx *= speed;
        //enemy移動
        e.px += e.vx;
        */

        clear(64, 128, 255);
        line(0, height / 2, width, height / 2);
        image(enemyImg, e.px, e.py);
        image(playerImg, p.px, p.py);

        text(e.vx, 0, 20);
        text(speed, 0, 40);
    }
}
