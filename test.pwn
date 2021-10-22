#include <a_samp>
#include <adzan>

main() 
{
	if(GetPrayTime() == 0) return print("Adzan Error");
	SetTimer("PrintConsole", 10000, 0);
	return 1;
}

forward PrintConsole();
public PrintConsole()
{
	printf("Subuh : %i, Duhur : %i, Ashar : %i, Maghrib : %i, Isya : %i", GetSubuhTime(), GetDuhurTime(), GetAsharTime(), GetMaghribTime(), GetIsyaTime());
}

OnGameModeInit()
{
	print("Game Inited");
	return 1;
}
