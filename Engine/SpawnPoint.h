#pragma once
#include <vector>
#include <random>
#include "Ball.h"

class SpawnPoint
{
public:
	SpawnPoint(std::mt19937& rng, std::vector<Ball>& container, float radius, Vec2 pos, float minvx, float maxvx, float vy, float period)
		:
		rng(rng),
		container(container),
		radius(radius),
		pos(pos),
		xDist(std::uniform_real_distribution<float>(minvx, maxvx)),
		vy(vy),
		period(period)
	{}
	void Update(float dt)
	{
		periodTime += dt;

		if (periodTime >= period)
		{
			periodTime -= period;
			container.emplace_back(Ball{ pos, radius, Vec2(xDist(rng), vy) });
		}
	}
private:
	std::mt19937& rng;
	std::vector<Ball>& container;
	std::uniform_real_distribution<float> xDist;
	float radius;
	Vec2 pos;
	float vy;
	float period;
	float periodTime = 0.0f;
};