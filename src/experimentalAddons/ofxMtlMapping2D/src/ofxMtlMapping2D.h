#pragma once

// OF
#include "ofMain.h"

// Addons
#include "ofxXmlSettings.h"

//Mapping
#include "ofxMtlMapping2DVertex.h"
#include "ofxMtlMapping2DQuad.h"
#include "ofxMtlMapping2DGrid.h"
#include "ofxMtlMapping2DTriangle.h"
#include "ofxMtlMapping2DMask.h"
#include "ofxMtlMapping2DShape.h"

#include "mtlUtils.h"


//========================================================================
class ofxMtlMapping2D {
    
    public:    
        ofxMtlMapping2D();
        virtual ~ofxMtlMapping2D();
        
        void init(int width, int height, string mappingXmlFilePath = "mapping/xml/shapes.xml", string uiXmlFilePath = "mapping/controls/mapping.xml", int numSample = 0);
        void update();
        
        void bind();
        void unbind();
        void drawFbo();
        void draw();
        void toggle();
    
        void mouseMoved(int x, int y);
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mousePressed(ofMouseEventArgs &e);
        void mouseReleased(int x, int y, int button);
        void keyPressed(int key);
        void windowResized(ofResizeEventArgs &e);

        vector<ofPolyline*> getMaskShapes();
        void chessBoard(int nbOfCol = 10);
    
        void deleteShape();

    private:
        string _mappingXmlFilePath;
        ofFbo _fbo;
        ofxXmlSettings _shapesListXML;
        list<ofxMtlMapping2DShape*>::iterator iteratorForShapeWithId(int shapeId);

        void render();
    
        void createQuad(float _x, float _y);
        void createGrid(float _x, float _y);
        void createTriangle(float _x, float _y);
        void createMask(float _x, float _y);
        
    
        void loadShapesList();
        void saveShapesList();
    
        void addListeners();
        void removeListeners();
};