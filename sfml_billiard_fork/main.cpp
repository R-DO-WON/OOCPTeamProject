#include "BaseGame.h"
#include "SampleGame.h"

int main(void)
{
	// 게임 생성 
	BaseGame&& game = SampleGame(1024, 1024, 60);
	
	// 게임 실행 
	game.run();

	return 0;
}
