#include <iostream>
#include <assert.h>
#include "emsdk/upstream/emscripten/cache/sysroot/include/emscripten/val.h"
#include "emsdk/upstream/emscripten/cache/sysroot/include/emscripten/emscripten.h"
#include "emsdk/upstream/emscripten/cache/sysroot/include/emscripten/html5.h"
#include "Tuple.hpp"
#include "Helper.hpp"
#include "Canvas.hpp"

using emscripten::val;

class Projectile{
    public: 
        Point position;
        Vector velocity;
        Projectile(Point pos, Vector vel);
};

Projectile::Projectile(Point pos, Vector vel){
    position = pos;
    velocity = vel;
}

class Environment{
    public:
        Vector gravity;
        Vector wind;
        Environment(Vector grav, Vector win);
};

Environment::Environment(Vector grav, Vector win){
    gravity = grav;
    wind = win;
}

Projectile tick(Environment env, Projectile proj){
    Point position = proj.position + proj.velocity;
    Vector velocity = proj.velocity + env.gravity + env.wind;
    return Projectile(position,velocity);
}

thread_local const val document = val::global("document");

int main(){
    Projectile p = Projectile(Point(0,1,0), Vector::norm(Vector(1,1,0)));
    Environment e = Environment(Vector(0,-0.1,0), Vector(0.01, 0, 0));

    while (p.position.y >= 0){
        std::cout << "x: " << p.position.x << " y:   " << p.position.y << "\n";
        p = tick(e,p);
    }

    Canvas myCanvas = Canvas(100,100);

    const char testarray[] = {'a', 'b', 'c', 'd', 'e', 'f', '\0', 'h'};

    EM_ASM(document.getElementById('canvas').id = 'myCanvas');

    EMSCRIPTEN_RESULT r = emscripten_set_canvas_element_size("#myCanvas", 100, 100);
    assert(r == EMSCRIPTEN_RESULT_SUCCESS);

    int res = EM_ASM_INT({
        var ctx= Module['canvas'].getContext('2d');
        var data = ctx.getImageData(0,0,100,100);
        console.log(data);
        for (let i = 0; i < data.data.length; i += 4){
           data.data[i] = 255; //- data.data[i];
            data.data[i+1] = 0;//255- data.data[i+1];
            data.data[i+2] = 0;//255- data.data[i+2];
            data.data[i+3] = 255;
         }
        ctx.putImageData(data,0,0);
        //console.log(Module.UTF8ToString($0));
        console.log('Data: ' + HEAP32[$0>>2]);

        let test = HEAP32[$0>>2];
        console.log(test);

        const bytearray = [];
         bytearray[0] = 0;
         bytearray[1] = 0;
         bytearray[2] = 0;
         bytearray[3] = 0;
        for (var index = 0; index < bytearray.length; index ++) {
            var byte = test & 0xff;
            bytearray [ index ] = byte;
            test = (test - byte) / 256;
        }
        console.log(bytearray);

    }, testarray);

    //ctx.set("fillStyle", "green");
    //ctx.call<void>("fillRect", 10, 10, 150, 100);


    Canvas c = Canvas(5,3);
    Color c1 = Color(1.5, 0, 0);
    Color c2 = Color(0, 0.5, 0);
    Color c3 = Color(-0.5, 0, 1);

    c.setPixel(0,0,c1);
    c.setPixel(2,1,c2);
    c.setPixel(4,2,c3);

    unsigned char* js = Canvas::to_js(c);

    std::cout << (unsigned int) js[0] << "\n";
    std::cout << (unsigned int) js[1] << "\n";
    std::cout << (unsigned int) js[2] << "\n";
    std::cout << (unsigned int) js[3] << "\n";
    std::cout << (unsigned int) js[4] << "\n";
    std::cout << (unsigned int) js[5] << "\n";
    std::cout << (unsigned int) js[6] << "\n";
    std::cout << (unsigned int) js[22] << "\n";
    std::cout << (unsigned int) js[42] << "\n";
    std::cout << (unsigned int) js[43] << "\n";
    std::cout << (unsigned int) js[44] << "\n";
}