#include"libOne.h"
struct VEC2 {
    float x = 0, y = 0;
};
struct UNKO {
    VEC2 pos;
    VEC2 vel;
    VEC2 acc;
};

void gmain() {
    window(1600, 300);
    int unkoImg = loadImage("assets\\unkoWhite.png");
    struct UNKO player = { width / 2,      height / 2 - 47 };
    struct UNKO enemy = { width / 2 + 200,  height / 2 - 47 };
    float speed = 0;
    float maxSpeed = 10;
    float maxForce = 1.0f;
    float nearDist = 100;
    rectMode(CENTER);
    while (notQuit) {
        //�e�L�X�g�\���ʒu��
        float py = 20;

        clear(64,128,255);

        //�v���C���[�̈ʒu
        if (isTrigger(MOUSE_LBUTTON)) {
            player.pos.x = mouseX;
        }

        //enemy����player�ւ̃x�N�g��
        float desire_x = player.pos.x - enemy.pos.x;
        fill(255);
        text("desire_x=" + (let)desire_x, 0, py); py += 20;

        //����
        float dist = absolute(desire_x);
        //�X�s�[�h������B�߂��Ȃ�����X�s�[�h�𗎂Ƃ�
        speed = maxSpeed;
        if (dist < nearDist) {
             speed = maxSpeed * dist / nearDist;
        }
        //�x�N�g���̑傫����speed�ɂ���
        if (dist > 0) {
            desire_x *= speed / dist;
        }
        //�����x
        enemy.acc.x = desire_x - enemy.vel.x;
        dist = absolute(enemy.acc.x);
        if (dist > maxForce) {
            enemy.acc.x *= maxForce / dist;
        }

        //enemy�ړ�
        enemy.pos.x += enemy.vel.x;
        enemy.vel.x += enemy.acc.x;
        text("enemy.vel.x=" + (let)enemy.vel.x, 0, py); py += 20;
        text("enemy.acc.x=" + (let)enemy.acc.x, 0, py); py += 20;
        text("enemy.pos.x=" + (let)enemy.pos.x, 0, py); py += 20;
        text("player.pos.x=" + (let)player.pos.x, 0, py); py += 20;

        noStroke();
        fill(128, 64, 0);
        rect(width/2, height / 4*3, width, height / 2);
        imageColor(0, 128, 0);
        image(unkoImg, enemy.pos.x, enemy.pos.y);
        imageColor(255, 163, 229);
        image(unkoImg, player.pos.x, player.pos.y);

    }
}
