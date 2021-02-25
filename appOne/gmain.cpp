#include"libOne.h"
struct UNKO {
   float px = 0, py = 0, vx = 0, vy = 0, ax = 0, ay=0, dx=0,dy=0;
};

void gmain() {
    window(1600,900);
    int playerImg = loadImage("assets\\unkoPink.png");
    int enemyImg = loadImage("assets\\unkoWhite.png");
    struct UNKO p = { width/2,      height / 2 - 50 };
    struct UNKO e = { width/2+200,  height / 2 - 50 };
    float speed = 0;
    float maxSpeed = 10;
    float force = 0.1;
    float nearDist = 50;
    float prePx;
    rectMode(CENTER);
    while (notQuit) {
        //プレイヤーの位置
        if (isTrigger(MOUSE_LBUTTON)) {
            p.px = mouseX;
            prePx = e.px;
        }
        //enemyからplayerへのベクトル
        e.dx = p.px - e.px;
        //距離
        float dist = absolute(e.dx);
        //if (dist > 0.001f) {
            //ベクトルの長さを1にする
            if (dist != 0) {
                e.dx /= dist;
            }
            //速度調節
            if (dist > nearDist) {
                //動き始め
                if (speed < maxSpeed) {
                    speed += force;
                }
                else {
                    speed = maxSpeed;
                }
            }
            else {
                 //近づいたらスピードを落とす
                 speed = maxSpeed * dist / nearDist;
            }
            //最終的なベクトル
            e.vx = e.dx * speed;
        //}

        //enemy移動
        e.px += e.vx;

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
        text("e.vx=" + (let)e.vx, 0, 20);
        text("e.dx=" + (let)e.dx, 0, 40);
        text("dist=" + (let)dist, 0, 60);
        text("speed=" + (let)speed, 0, 80);

    }
}
