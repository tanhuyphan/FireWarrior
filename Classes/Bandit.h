#ifndef _BANDIT_H_
#define _BANDIT_H_
#include "cocos2d.h"
#include "GamePlayLayer.h"
#include"GameObject.h"
#include"Physics\PhysicsHandler.h"
#include"MainPlayer.h"
#include"PoolEnemyHit.h"
#include"EnemyHit.h"

class Bandit:public GameObject

{
public:
	Bandit();
	~Bandit();
	CREATE_FUNC(Bandit);
	virtual bool init();
	enum  Direction
	{
		LEFT,
		RIGHT,
		DOWN,
		UP
	};
	void Idle();
	void Attack();
	void AttackRight();
	void Run();
	void TakeDamage();
	void updateHealthBar(float percent);
	void setHealthBar(float percent);
	cocos2d::ui::LoadingBar *healthbarBandit;
	virtual void onContactBeganWith(GameObject* obj) override;
	virtual void onContactPostSolveWith(GameObject* obj, cocos2d::PhysicsContact& contact, const cocos2d::PhysicsContactPostSolve& solve) override;
	virtual void onContactSeparateWith(GameObject* obj, cocos2d::PhysicsContact& contact) override;
	virtual void onContactPreSolveWith(GameObject* obj, cocos2d::PhysicsContact& contact, cocos2d::PhysicsContactPreSolve& solve) override;
	void Fight();

	void enalbeAI(MainPlayer *player);
	void scheduleUpdateAI(float delta);

private:
	cocos2d::Sprite*_Enemy;
	float Health;
	float ObjDmg;
	float  _timeUpdateAI;
	MainPlayer* _player;
	Direction _direction;
	PoolEnemyHit*_poolEnemyHit;
	void chasePlayer();
};



#endif // !_BANDIT_H_

