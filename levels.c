void makeStrech(Object *obj, int X, int Y, int dX, int dY, int length) {
	int i;
	for(i=0;i<length;i++) {
		createInstance(obj, 0, X, Y, 0, 0, 0);
		X += dX;
		Y += dY;
	}
}

void level0() {
	createInstance(cannon, 0, 150, 450, 0, 0, 0);

	makeStrech(wall, 16, 16, 32, 0, 800/32);
	printf("tail->PREV: %p\n", GAME.tailInst->PREV);
	makeStrech(wall, 800-16, 16, 0, 32, 600/32);
	printf("tail->PREV: %p\n", GAME.tailInst->PREV);
	makeStrech(wall, 16, 600-16, 32, 0, 800/32);
	printf("tail->PREV: %p\n", GAME.tailInst->PREV);

	createInstance(target, 0, 700, 300, 0, 0, 0);
}

void level1() {
	createInstance(cannon, 0, 650, 150, 0, 0, 0);

	makeStrech(wall, 16, 600-16, 32, 0, 800/32);
	makeStrech(wall, 800-16, 16, 0, 32, 600/32);

	createInstance(orb, 0, 400, 300, 0, 0, 0);

	createInstance(target, 0, 150, 450, 0, 0, 0);
}

void level2() {
	createInstance(cannon, 0, 80, 150, 0, 0, 0);

	makeStrech(wall, 16, 16, 0, 32, 400/32);
	makeStrech(wall, 16, 600-16, 32, 0, 800/32);
	makeStrech(wall, 800-16, 16, 0, 32, 300/32);
	makeStrech(wall, 32*5+16, 16, 0, 32, 300/32);

	createInstance(orb, 0, 32*5+16, 300+16, 0, 0, 0)->scale = 25;
	createInstance(orb, 0, 32*16+16, 500, 0, 0, 0)->scale = 10;

	createInstance(target, 0, 700, 80, 0, 0, 0);
}

void level3() {
	createInstance(cannon, 0, 600, 500, 0, 0, 0);

	makeStrech(wall, 16, 16, 32, 0, 800/32);
	makeStrech(wall, 400, 300, 0, 32, 300/32);

	int i;
	for(i=0;i<6;i++) {
		createInstance(sizeUp, 0, 32*(i+10), 100, 0, 0, 0)->A = 3;
	}

	createInstance(orb, 0, 80, 200, 0, 0, 0);

	createInstance(target, 0, 100, 500, 0, 0, 0);
}

void level4() {
	createInstance(cannon, 0, 700, 80, 0, 0, 0);

	makeStrech(wall, 16, 16, 32, 0, 800/32);
	makeStrech(wall, 800-16, 16, 0, 32, 600/32+1);

	createInstance(sizeDown, 1, 32*10+16, 32*3+16, 0, 0, 0);
	createInstance(sizeDown, 0, 32*10+16, 32*6+16, 0, 0, 0);
	createInstance(sizeDown, 0, 32*10+16, 32*10+16, 0, 0, 0);
	createInstance(sizeDown, 0, 32*10+16, 32*5+16, 0, 0, 0);
	createInstance(sizeDown, 0, 32*14+16, 32*4+16, 0, 0, 0)->B = 4;
	createInstance(sizeDown, 0, 32*14+16, 32*8+16, 0, 0, 0)->B = 4;
	createInstance(sizeDown, 0, 32*14+16, 32*12+16, 0, 0, 0)->B = 4;

	createInstance(target, 0, 200, 270, 0, 0, 0);
	createInstance(orb, 0, 200, 400, 0, 0, 0)->scale = 65;
}

void level5() {
	createInstance(cannon, 0, 80, 300, 0, 0, 0);
	
	createInstance(antiorb, 0, 60, 60, 0, 0, 0);
	createInstance(antiorb, 0, 740, 200, 0, 0, 0);
	createInstance(antiorb, 0, 60, 540, 0, 0, 0);
	createInstance(antiorb, 0, 740, 400, 0, 0, 0);
	createInstance(orb, 0, 400, 300, 0, 0, 0);

	createInstance(target, 0, 720, 300, 0, 0, 0);
}

void level6() {

}

void level7() {

}

void level8() {

}

void level9() {

}

void level10() {
	createInstance(cannon, 0, 150, 450, 0, 0, 0);

	int i;
	for(i=0;i<800/32;i++) {
		createInstance(wall, 0, 32*i+16, 600-16, 1, 0, 0);
	}
	for(i=0;i<600/32;i++) {
		createInstance(wall, 0, 16, 32*i+16, -1, 0, 0);
		createInstance(wall, 0, 800-16, 32*i+16, -1, 0, 0);
	}
	createInstance(sizeUp, 0, 800-11*32+16, 600-32+16, 0, 0, 0)->A = 2;
	createInstance(sizeUp, 0, 800-11*32+16, 600-32*2+16, 0, 0, 0)->A = 2;
	createInstance(sizeUp, 0, 800-11*32+16, 600-32*3+16, 0, 0, 0)->A = 2;
	createInstance(sizeUp, 0, 800-11*32+16, 600-32*4+16, 0, 0, 0)->A = 2;

	createInstance(sizeDown, 0, 3*32+16, 16, 0, 0, 0);
	createInstance(sizeDown, 0, 5*32+16, 16, 0, 0, 0);
	createInstance(sizeDown, 0, 7*32+16, 16, 0, 0, 0);
	createInstance(sizeDown, 0, 9*32+16, 16, 0, 0, 0);
	createInstance(sizeDown, 0, 11*32+16,16, 0, 0, 0);
	createInstance(sizeDown, 0, 13*32+16,16, 0, 0, 0);
	createInstance(sizeDown, 0, 15*32+16,16, 0, 0, 0);
	createInstance(sizeDown, 0, 17*32+16,16, 0, 0, 0);
	createInstance(sizeDown, 0, 19*32+16,16, 0, 0, 0);
	createInstance(sizeDown, 0, 21*32+16,16, 0, 0, 0);

	createInstance(target, 0, 700, 300, 0, 0, 0);


	createInstance(orb, 0, 200, 300, 0, 0, 0)->scale = 10;
	createInstance(orb, 0, 600, 300, 0, 0, 0)->scale = 5;
	createInstance(orb, 0, 400, 200, 0, 0, 0)->scale = 20;

	myBounce = createInstance(bounce, 0, 0, 0, 0, 0, 0);
		myBounce->scale = 4;
	createInstance(mouse, 0, 0, 0, 0, 0, 0);
}
