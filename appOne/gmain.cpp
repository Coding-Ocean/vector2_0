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
        //�v���C���[�̈ʒu
        if (isTrigger(MOUSE_LBUTTON)) {
            p.px = mouseX;
            prePx = e.px;
        }
        //enemy����player�ւ̃x�N�g��
        e.dx = p.px - e.px;
        //����
        float dist = absolute(e.dx);
        //if (dist > 0.001f) {
            //�x�N�g���̒�����1�ɂ���
            if (dist != 0) {
                e.dx /= dist;
            }
            //���x����
            if (dist > nearDist) {
                //�����n��
                if (speed < maxSpeed) {
                    speed += force;
                }
                else {
                    speed = maxSpeed;
                }
            }
            else {
                 //�߂Â�����X�s�[�h�𗎂Ƃ�
                 speed = maxSpeed * dist / nearDist;
            }
            //�ŏI�I�ȃx�N�g��
            e.vx = e.dx * speed;
        //}

        //enemy�ړ�
        e.px += e.vx;

        /*
        //�v���C���[�̈ʒu
        p.px = mouseX;
        //enemy����player�ւ̃x�N�g��
        e.vx = p.px - e.px;
        //����
        float dist = e.vx > 0 ? e.vx : -e.vx;
        //�x�N�g���̒������P�ɂ���
        if (dist != 0){
            e.vx /= dist;
        }
        //�߂Â�����X�s�[�h�𗎂Ƃ�
        if (dist > nearDist){
            speed = maxSpeed;
        }
        else{
            speed = map(dist, 0, nearDist, 0, maxSpeed);
        }
        //�ŏI�I�ȃx�N�g��
        e.vx *= speed;
        //enemy�ړ�
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
