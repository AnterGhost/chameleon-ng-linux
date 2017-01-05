#pragma once

#define MAX_PLAYER_NAME_LENGTH 32
#define SIGNED_GUID_LEN 32

typedef struct player_info_s {
	private:
		int64_t unknown;
	public:
		union {
			int64_t xuid;
			struct {
				int xuid_low;
				int xuid_high;
			};
		};
		char name[MAX_PLAYER_NAME_LENGTH + 96];
		int userid;
		int m_nUserID;
		char guid[SIGNED_GUID_LEN + 1];
		unsigned int friendsid;
		char friendsname[MAX_PLAYER_NAME_LENGTH + 96];
		bool fakeplayer;
		bool ishltv;
		unsigned int customfiles[4];
		unsigned char filesdownloaded;
} player_info_t;

class IVEngineClient {
	public:
		inline bool GetPlayerInfo(int index, player_info_t* playerinfo) {
			return GetVirtualFunction<bool(*)(IVEngineClient*, int, player_info_t*)>(this, 8)(this, index, playerinfo);
		}

		inline int GetPlayerForUserID(int userid) {
			return GetVirtualFunction<bool(*)(IVEngineClient*, int)>(this, 9)(this, userid);
		}

		inline int GetLocalPlayer() {
			return GetVirtualFunction<int(*)(IVEngineClient*)>(this, 12)(this);
		}

		inline bool IsInGame() {
			return GetVirtualFunction<bool(*)(IVEngineClient*)>(this, 26)(this);
		}

		inline bool IsConnected() {
			return GetVirtualFunction<bool(*)(IVEngineClient*)>(this, 27)(this);
		}

		void ClientCmd_Unrestricted(const char* command, bool delayed = false) {
			return GetVirtualFunction<void(*)(IVEngineClient*, const char*, bool)>(this, 114)(this, command, delayed);
		}
};

extern IVEngineClient* engine;