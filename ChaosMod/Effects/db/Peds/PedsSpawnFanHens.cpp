#include <stdafx.h>

#define FAN_HENS_AMOUNT 5

static void OnStart()
{
	static const Hash modelHash = GET_HASH_KEY("a_c_hen");

	Hash relationshipGroup;
	ADD_RELATIONSHIP_GROUP("_FAN_HENS", &relationshipGroup);
	SET_RELATIONSHIP_BETWEEN_GROUPS(0, relationshipGroup, GET_HASH_KEY("PLAYER"));
	SET_RELATIONSHIP_BETWEEN_GROUPS(0, GET_HASH_KEY("PLAYER"), relationshipGroup);

	Ped playerPed = PLAYER_PED_ID();
	Vector3 playerPos = GET_ENTITY_COORDS(playerPed, false);

	for (int i = 0; i < FAN_HENS_AMOUNT; i++)
	{
		Ped ped = CreatePoolPed(28, modelHash, playerPos.x, playerPos.y, playerPos.z, 0.f);
		SET_PED_RELATIONSHIP_GROUP_HASH(ped, relationshipGroup);
		SET_PED_AS_GROUP_MEMBER(ped, GET_PLAYER_GROUP(PLAYER_ID()));
	}
}

// clang-format off
REGISTER_EFFECT(OnStart, nullptr, nullptr, EffectInfo
	{
		.Name = "I Love Cocks",
		.Id = "peds_spawnfanhens",
		.EffectGroupType = EEffectGroupType::SpawnCompanion
	}
);