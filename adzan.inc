/****************************************************************
 *              Adzan v1.0b              						*
 *                                                              *
 *        (c) Copyright 2021, SAMPINDO x ANGGA                  *
 *              This file is provided as is.                    *
 *                                                              *
 ****************************************************************/                                                                                                                                                                                         
#if defined _adzan_included
  #endinput
#endif
#define _adzan_included
#if !defined _requests_included
	#tryinclude "requests"
#endif
#if !defined _requests_included
	#error Adzan Need Pawn Request Included Download : github.com/Southclaws/pawn-requests
#endif
//=== VAriable Storage ===//
enum TIME
{
    SUBUH,  // 0
    DUHUR,  // 1
    ASHAR,  // 2
    MAGHRIB,  // 3
    ISHA,  // 4
}
new WaktuSholat[TIME];
new m[6];
//=== Internal Function ===//
new RequestsClient:client;
static AdzanInit() {
	m[0] = 65, m[1] = 78, m[2] = 71, m[3] = 71, m[4] = 65, m[5] = 0;
    client = RequestsClient("https://angular211-athallahdzaki.vercel.app/", RequestHeaders("Mighty", m));
	printf("Adzan Time By %s", m);
	DO522();
}
static DO522()
{
	if(RequestJSON(
		client,
		"",
		HTTP_METHOD_GET,
		"F33XS",
		.headers = RequestHeaders()
	)) return 1;
	return 0;
}
forward F33XS(Request:ae, E_HTTP_STATUS:sttxz, Node:as);
public F33XS(Request:ae, E_HTTP_STATUS:sttxz, Node:as) {
	if(sttxz != HTTP_STATUS_OK)
		return print("Website Mighty Down Right Now");
	JsonGetInt(as, "521", WaktuSholat[SUBUH]);
	JsonGetInt(as, "AE", WaktuSholat[DUHUR]);
	JsonGetInt(as, "M3", WaktuSholat[ASHAR]);
	JsonGetInt(as, "EC2", WaktuSholat[MAGHRIB]);
	JsonGetInt(as, "AX", WaktuSholat[ISHA]);
	return 1;
}
public OnGameModeInit()
{
	AdzanInit();
	#if defined Adzan_OnGameModeInit
		return Adzan_OnGameModeInit();
	#else
	    return 1;
	#endif
}
#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif
#if defined Adzan_OnGameModeInit
	forward Adzan_OnGameModeInit();
#endif
#define OnGameModeInit Adzan_OnGameModeInit
//=== End of Internal Function ===//
//=== Native And Definition ===//
stock GetSubuhTime() return WaktuSholat[SUBUH];
stock GetDuhurTime() return WaktuSholat[DUHUR];
stock GetAsharTime() return WaktuSholat[ASHAR];
stock GetMaghribTime() return WaktuSholat[MAGHRIB];
stock GetIsyaTime() return WaktuSholat[ISHA];
stock GetPrayTime() return DO522();
