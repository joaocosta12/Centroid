#include <iostream>
#include <thread>
#include <stdio.h>
#include <vector>
#include <list>
#include <fstream>
#include <vector>

#include <GL/glut.h>

using namespace std;

struct Point{
	double x, y, z;
	int intensidade;
	int r, g, b;

};

class Objeto{

	vector<Point> ponto;
	double centroX, centroY, centroZ;

	public:
	void setPonto(Point pontinho){
		ponto.push_back(pontinho);
	}

	vector<Point> getPonto(){
		return ponto;	
	}
	
	void imprime(){
		for (vector<Point>::iterator it = ponto.begin() ; it != ponto.end(); ++it)
			cout << (*it).x << " " << (*it).y << " " << (*it).z << " " << (*it).intensidade << " " << (*it).b << " " << (*it).g << " " << (*it).r << " " << endl;
		
	}

	void centro(){
		for (vector<Point>::iterator it = ponto.begin() ; it != ponto.end(); ++it){
			centroX += (*it).x;
			centroY += (*it).y;
			centroZ += (*it).z;
		}

		centroX = centroX/(ponto.size());
		centroY = centroY/(ponto.size());
		centroZ = centroZ/(ponto.size());
				
	}
	
	void imprimeCentro(){
		cout << "Centro: (" << centroX << ", " << centroY << ", " << centroZ << ")." << endl;
	}
};


int main(int argc, char** argv)
{
	Objeto carro, rua, placa, arvore, ceu, calcada, casa, erro;

	// 			B	G	R
	//CARRO -	255	0	255
	//RUA -		128	128	128
	//PLACA -	0	0	0
	//ARVORE -	0	128	0
	//CEU -		255	0	0
	//CALCADA -	0	128	128
	//CASA -	0	0	255
	
	Point points;

	fstream reader_file;
    reader_file.open ("color_cloud.xyz");
	
	
	if(reader_file.is_open()){    
		
		while(!reader_file.eof()){
		reader_file >> points.x >> points.y >> points.z >> points.intensidade >> points.b >> points.g >> points.r;
		
		if(points.b == 255 && points.g == 0 && points.r == 255)
			carro.setPonto(points);
		else if(points.b == 128 && points.g == 128 && points.r == 128)
			rua.setPonto(points);
		else if(points.b == 0 && points.g == 0 && points.r == 0)
			placa.setPonto(points);
		else if(points.b == 0 && points.g == 128 && points.r == 0)
			arvore.setPonto(points);
		else if(points.b == 255 && points.g == 0 && points.r == 0)
			ceu.setPonto(points);
		else if(points.b == 0 && points.g == 128 && points.r == 128)
			calcada.setPonto(points);
		else if(points.b == 0 && points.g == 0 && points.r == 255)
			casa.setPonto(points);
		else
			erro.setPonto(points);
		}
	}
	else{
	cout << "Arquivo não encontrado" << endl;	
	}
    reader_file.close();

	//LEITURA
	//carro.imprime();
	//rua.imprime();
	//placa.imprime();
	//arvore.imprime();
	//ceu.imprime();
	//calcada.imprime();
	//casa.imprime();

	//CENTROIDE
	carro.centro();
	rua.centro();
	placa.centro();
	arvore.centro();
	ceu.centro();
	calcada.centro();
	casa.centro();
	
	//IMPRIME CENTRO
	carro.imprimeCentro();
	rua.imprimeCentro();
	placa.imprimeCentro();
	arvore.imprimeCentro();
	ceu.imprimeCentro();
	calcada.imprimeCentro();
	casa.imprimeCentro();
	
	
	return 0;
}
