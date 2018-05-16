#include "Utility.h"

SDL_Texture* loadTexture(std::string path, Renderer r) 
{
	SDL_Texture* texture = NULL; 
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() ); 
	if( loadedSurface == NULL ) 
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	} 
	else
	{
		texture = SDL_CreateTextureFromSurface(r.get_SDL_Renderer(), loadedSurface); 
		if( texture == NULL ) 
		{ 
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() ); 
		} 
		SDL_FreeSurface( loadedSurface ); 
	} 
	return texture;
}

std::string parseLine(std::string line, std::string getData)
{
	int dataPos = line.find(getData);
	line = line.substr(dataPos);
	
	int endDataPos = line.find(" ");
	if (endDataPos != std::string::npos)
	{
		line.erase(endDataPos, -1);
	}

	line.erase(0, getData.length());

	return line;
}

std::string parseBracketData(std::string line, int num)
{
	//012345
	//1,2,3,
	line.erase(0, 1);
	line.replace(line.length()-1, 1, ",");
	int cPos;
	for (int i = 0; i < num; i++)
	{
		cPos = line.find(",");
		line.erase(0, cPos+1);
	}

	cPos = line.find(",");
	line.erase(cPos);
	return line;
}
