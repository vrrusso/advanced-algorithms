#include<iostream>
#include<vector>
#include<queue>


using namespace std;

#define S 9

typedef struct{
    char tile1;
    char tile2;
    char tile3;
    char tile4;
    char tile5;
    char tile6;
    char tile7;
    char tile8;
    char tile9;
}Dataset;

typedef struct{
    Dataset board;
    string moves;
    int depth;
}State;

bool equal(Dataset d1, Dataset d2){
    if(d1.tile1==d2.tile1 && d1.tile2==d2.tile2 && d1.tile3==d2.tile3 && d1.tile4==d2.tile4 && d1.tile5==d2.tile5 && d1.tile6==d2.tile6 && d1.tile7==d2.tile7 && d1.tile8==d2.tile8 && d1.tile9==d2.tile9)
        return true;
    return false;
}

bool foi_visitado(Dataset target, vector<Dataset> visitados){
    for(int i= 0;i< (int) visitados.size();i++){
        if(equal(target,visitados[i]))
            return true;
    }
    return false;
}

string insert_adjacent_state_queue(State atual,Dataset final,vector<Dataset> &visitados,queue<State> &next){
    if(atual.board.tile1 == 'x'){
        //testar d e r
        State r;r.board.tile1=atual.board.tile2;r.board.tile2 = atual.board.tile1;r.board.tile3=atual.board.tile3;r.board.tile4=atual.board.tile4;r.board.tile5=atual.board.tile5;r.board.tile6=atual.board.tile6;r.board.tile7=atual.board.tile7;r.board.tile8=atual.board.tile8;r.board.tile9=atual.board.tile9;
        r.depth = atual.depth+1;
        r.moves = atual.moves+"r";
        if(!foi_visitado(r.board,visitados)){
            next.push(r);
            visitados.push_back(r.board);
        }
        r.board.tile1=atual.board.tile4;r.board.tile2 = atual.board.tile2;r.board.tile3=atual.board.tile3;r.board.tile4=atual.board.tile1;r.board.tile5=atual.board.tile5;r.board.tile6=atual.board.tile6;r.board.tile7=atual.board.tile7;r.board.tile8=atual.board.tile8;r.board.tile9=atual.board.tile9;
        r.depth = atual.depth+1;
        r.moves = atual.moves+"d";
        if(!foi_visitado(r.board,visitados)){
            next.push(r);
            visitados.push_back(r.board);
        }
    }
    else if(atual.board.tile2 == 'x'){
        //testando l, r e d
        State r;r.board.tile1=atual.board.tile1;r.board.tile2 = atual.board.tile3;r.board.tile3=atual.board.tile2;r.board.tile4=atual.board.tile4;r.board.tile5=atual.board.tile5;r.board.tile6=atual.board.tile6;r.board.tile7=atual.board.tile7;r.board.tile8=atual.board.tile8;r.board.tile9=atual.board.tile9;
        r.depth = atual.depth+1;
        r.moves = atual.moves+"r";
        if(!foi_visitado(r.board,visitados)){
            next.push(r);
            visitados.push_back(r.board);
        }
        r.board.tile1=atual.board.tile1;r.board.tile2 = atual.board.tile5;r.board.tile3=atual.board.tile3;r.board.tile4=atual.board.tile4;r.board.tile5=atual.board.tile2;r.board.tile6=atual.board.tile6;r.board.tile7=atual.board.tile7;r.board.tile8=atual.board.tile8;r.board.tile9=atual.board.tile9;
        r.depth = atual.depth+1;
        r.moves = atual.moves+"d";
        if(!foi_visitado(r.board,visitados)){
            next.push(r);
            visitados.push_back(r.board);
        }
        r.board.tile1=atual.board.tile2;r.board.tile2 = atual.board.tile1;r.board.tile3=atual.board.tile3;r.board.tile4=atual.board.tile4;r.board.tile5=atual.board.tile5;r.board.tile6=atual.board.tile6;r.board.tile7=atual.board.tile7;r.board.tile8=atual.board.tile8;r.board.tile9=atual.board.tile9;
        r.depth = atual.depth+1;
        r.moves = atual.moves+"l";
        if(!foi_visitado(r.board,visitados)){
            next.push(r);
            visitados.push_back(r.board);
        }
    }
    else if(atual.board.tile3 == 'x'){
        //testando l e d
        State r;r.board.tile1=atual.board.tile1;r.board.tile2 = atual.board.tile3;r.board.tile3=atual.board.tile2;r.board.tile4=atual.board.tile4;r.board.tile5=atual.board.tile5;r.board.tile6=atual.board.tile6;r.board.tile7=atual.board.tile7;r.board.tile8=atual.board.tile8;r.board.tile9=atual.board.tile9;
        r.depth = atual.depth+1;
        r.moves = atual.moves+"l";
        if(!foi_visitado(r.board,visitados)){
            next.push(r);
            visitados.push_back(r.board);
        }
        r.board.tile1=atual.board.tile1;r.board.tile2 = atual.board.tile2;r.board.tile3=atual.board.tile6;r.board.tile4=atual.board.tile4;r.board.tile5=atual.board.tile5;r.board.tile6=atual.board.tile3;r.board.tile7=atual.board.tile7;r.board.tile8=atual.board.tile8;r.board.tile9=atual.board.tile9;
        r.depth = atual.depth+1;
        r.moves = atual.moves+"d";
        if(!foi_visitado(r.board,visitados)){
            next.push(r);
            visitados.push_back(r.board);
        }
    }
    else if(atual.board.tile4 == 'x'){
        //testando u,r,d
        State r;r.board.tile1=atual.board.tile4;r.board.tile2 = atual.board.tile2;r.board.tile3=atual.board.tile3;r.board.tile4=atual.board.tile1;r.board.tile5=atual.board.tile5;r.board.tile6=atual.board.tile6;r.board.tile7=atual.board.tile7;r.board.tile8=atual.board.tile8;r.board.tile9=atual.board.tile9;
        r.depth = atual.depth+1;
        r.moves = atual.moves+"u";
        if(!foi_visitado(r.board,visitados)){
            next.push(r);
            visitados.push_back(r.board);
        }
        r.board.tile1=atual.board.tile1;r.board.tile2 = atual.board.tile2;r.board.tile3=atual.board.tile3;r.board.tile4=atual.board.tile5;r.board.tile5=atual.board.tile4;r.board.tile6=atual.board.tile6;r.board.tile7=atual.board.tile7;r.board.tile8=atual.board.tile8;r.board.tile9=atual.board.tile9;
        r.depth = atual.depth+1;
        r.moves = atual.moves+"r";
        if(!foi_visitado(r.board,visitados)){
            next.push(r);
            visitados.push_back(r.board);
        }
        r.board.tile1=atual.board.tile1;r.board.tile2 = atual.board.tile2;r.board.tile3=atual.board.tile3;r.board.tile4=atual.board.tile7;r.board.tile5=atual.board.tile5;r.board.tile6=atual.board.tile6;r.board.tile7=atual.board.tile4;r.board.tile8=atual.board.tile8;r.board.tile9=atual.board.tile9;
        r.depth = atual.depth+1;
        r.moves = atual.moves+"u";
        if(!foi_visitado(r.board,visitados)){
            next.push(r);
            visitados.push_back(r.board);
        }
    }
    else if(atual.board.tile5 == 'x'){
        //testando u,r,d,l
        State r;r.board.tile1=atual.board.tile1;r.board.tile2 = atual.board.tile5;r.board.tile3=atual.board.tile3;r.board.tile4=atual.board.tile4;r.board.tile5=atual.board.tile2;r.board.tile6=atual.board.tile6;r.board.tile7=atual.board.tile7;r.board.tile8=atual.board.tile8;r.board.tile9=atual.board.tile9;
        r.depth = atual.depth+1;
        r.moves = atual.moves+"u";
        if(!foi_visitado(r.board,visitados)){
            next.push(r);
            visitados.push_back(r.board);
        }
        r.board.tile1=atual.board.tile1;r.board.tile2 = atual.board.tile2;r.board.tile3=atual.board.tile3;r.board.tile4=atual.board.tile4;r.board.tile5=atual.board.tile6;r.board.tile6=atual.board.tile5;r.board.tile7=atual.board.tile7;r.board.tile8=atual.board.tile8;r.board.tile9=atual.board.tile9;
        r.depth = atual.depth+1;
        r.moves = atual.moves+"r";
        if(!foi_visitado(r.board,visitados)){
            next.push(r);
            visitados.push_back(r.board);
        }
        r.board.tile1=atual.board.tile1;r.board.tile2 = atual.board.tile2;r.board.tile3=atual.board.tile3;r.board.tile4=atual.board.tile4;r.board.tile5=atual.board.tile8;r.board.tile6=atual.board.tile6;r.board.tile7=atual.board.tile7;r.board.tile8=atual.board.tile5;r.board.tile9=atual.board.tile9;
        r.depth = atual.depth+1;
        r.moves = atual.moves+"d";
        if(!foi_visitado(r.board,visitados)){
            next.push(r);
            visitados.push_back(r.board);
        }
        r.board.tile1=atual.board.tile1;r.board.tile2 = atual.board.tile2;r.board.tile3=atual.board.tile3;r.board.tile4=atual.board.tile5;r.board.tile5=atual.board.tile4;r.board.tile6=atual.board.tile6;r.board.tile7=atual.board.tile7;r.board.tile8=atual.board.tile8;r.board.tile9=atual.board.tile9;
        r.depth = atual.depth+1;
        r.moves = atual.moves+"l";
        if(!foi_visitado(r.board,visitados)){
            next.push(r);
            visitados.push_back(r.board);
        }
    }
    else if(atual.board.tile6 == 'x'){
        //testando u,d e l
        State r;r.board.tile1=atual.board.tile1;r.board.tile2 = atual.board.tile2;r.board.tile3=atual.board.tile6;r.board.tile4=atual.board.tile4;r.board.tile5=atual.board.tile5;r.board.tile6=atual.board.tile3;r.board.tile7=atual.board.tile7;r.board.tile8=atual.board.tile8;r.board.tile9=atual.board.tile9;
        r.depth = atual.depth+1;
        r.moves = atual.moves+"u";
        if(!foi_visitado(r.board,visitados)){
            next.push(r);
            visitados.push_back(r.board);
        }
        r.board.tile1=atual.board.tile1;r.board.tile2 = atual.board.tile2;r.board.tile3=atual.board.tile3;r.board.tile4=atual.board.tile4;r.board.tile5=atual.board.tile5;r.board.tile6=atual.board.tile9;r.board.tile7=atual.board.tile7;r.board.tile8=atual.board.tile8;r.board.tile9=atual.board.tile6;
        r.depth = atual.depth+1;
        r.moves = atual.moves+"d";
        if(equal(r.board,final))
            return r.moves;
        if(!foi_visitado(r.board,visitados)){
            next.push(r);
            visitados.push_back(r.board);
        }
        r.board.tile1=atual.board.tile1;r.board.tile2 = atual.board.tile2;r.board.tile3=atual.board.tile3;r.board.tile4=atual.board.tile4;r.board.tile5=atual.board.tile6;r.board.tile6=atual.board.tile5;r.board.tile7=atual.board.tile7;r.board.tile8=atual.board.tile8;r.board.tile9=atual.board.tile9;
        r.depth = atual.depth+1;
        r.moves = atual.moves+"l";
        if(!foi_visitado(r.board,visitados)){
            next.push(r);
            visitados.push_back(r.board);
        }
    }
    else if(atual.board.tile7 == 'x'){
        //testando u e r
        State r;r.board.tile1=atual.board.tile1;r.board.tile2 = atual.board.tile2;r.board.tile3=atual.board.tile3;r.board.tile4=atual.board.tile7;r.board.tile5=atual.board.tile5;r.board.tile6=atual.board.tile6;r.board.tile7=atual.board.tile4;r.board.tile8=atual.board.tile8;r.board.tile9=atual.board.tile9;
        r.depth = atual.depth+1;
        r.moves = atual.moves+"u";
        if(!foi_visitado(r.board,visitados)){
            next.push(r);
            visitados.push_back(r.board);
        }
        r.board.tile1=atual.board.tile1;r.board.tile2 = atual.board.tile2;r.board.tile3=atual.board.tile3;r.board.tile4=atual.board.tile4;r.board.tile5=atual.board.tile5;r.board.tile6=atual.board.tile6;r.board.tile7=atual.board.tile8;r.board.tile8=atual.board.tile7;r.board.tile9=atual.board.tile9;
        r.depth = atual.depth+1;
        r.moves = atual.moves+"r";
        if(!foi_visitado(r.board,visitados)){
            next.push(r);
            visitados.push_back(r.board);
        }
    }
    else if(atual.board.tile8== 'x'){
        //testando u,r,l
        State r;r.board.tile1=atual.board.tile1;r.board.tile2 = atual.board.tile2;r.board.tile3=atual.board.tile3;r.board.tile4=atual.board.tile4;r.board.tile5=atual.board.tile8;r.board.tile6=atual.board.tile6;r.board.tile7=atual.board.tile7;r.board.tile8=atual.board.tile5;r.board.tile9=atual.board.tile9;
        r.depth = atual.depth+1;
        r.moves = atual.moves+"u";
        if(!foi_visitado(r.board,visitados)){
            next.push(r);
            visitados.push_back(r.board);
        }
        r.board.tile1=atual.board.tile1;r.board.tile2 = atual.board.tile2;r.board.tile3=atual.board.tile3;r.board.tile4=atual.board.tile4;r.board.tile5=atual.board.tile5;r.board.tile6=atual.board.tile6;r.board.tile7=atual.board.tile7;r.board.tile8=atual.board.tile9;r.board.tile9=atual.board.tile8;
        r.depth = atual.depth+1;
        r.moves = atual.moves+"r";
        if(equal(r.board,final))
            return r.moves;
        if(!foi_visitado(r.board,visitados)){
            next.push(r);
            visitados.push_back(r.board);
        }
        r.board.tile1=atual.board.tile1;r.board.tile2 = atual.board.tile2;r.board.tile3=atual.board.tile3;r.board.tile4=atual.board.tile4;r.board.tile5=atual.board.tile5;r.board.tile6=atual.board.tile6;r.board.tile7=atual.board.tile8;r.board.tile8=atual.board.tile7;r.board.tile9=atual.board.tile9;
        r.depth = atual.depth+1;
        r.moves = atual.moves+"l";
        if(!foi_visitado(r.board,visitados)){
            next.push(r);
            visitados.push_back(r.board);
        }
    }
    else{
        //testando u e l
        State r;r.board.tile1=atual.board.tile1;r.board.tile2 = atual.board.tile2;r.board.tile3=atual.board.tile3;r.board.tile4=atual.board.tile4;r.board.tile5=atual.board.tile5;r.board.tile6=atual.board.tile9;r.board.tile7=atual.board.tile7;r.board.tile8=atual.board.tile8;r.board.tile9=atual.board.tile6;
        r.depth = atual.depth+1;
        r.moves = atual.moves+"u";
        if(!foi_visitado(r.board,visitados)){
            next.push(r);
            visitados.push_back(r.board);
        }
        r.board.tile1=atual.board.tile1;r.board.tile2 = atual.board.tile2;r.board.tile3=atual.board.tile3;r.board.tile4=atual.board.tile4;r.board.tile5=atual.board.tile5;r.board.tile6=atual.board.tile6;r.board.tile7=atual.board.tile7;r.board.tile8=atual.board.tile9;r.board.tile9=atual.board.tile8;
        r.depth = atual.depth+1;
        r.moves = atual.moves+"l";
        if(!foi_visitado(r.board,visitados)){
            next.push(r);
            visitados.push_back(r.board);
        }
    }


    return "vazia";
}

void bfs(State puzzle){
    Dataset final;final.tile1='1';final.tile2='2';final.tile3='3';final.tile4='4';final.tile5='5';final.tile6='6';final.tile7='7';final.tile8='8';final.tile9='x';
    if(equal(puzzle.board,final)){
        cout<<endl;
        return;
    }

    vector<Dataset> visitados;

    queue<State> next;
    visitados.push_back(puzzle.board);

    string aux = insert_adjacent_state_queue(puzzle,final,visitados,next);
    if(aux != "vazia"){
        cout<<aux<<endl;
        return;
    }
    while(!next.empty()){
        State current = next.front();next.pop();
        string aux_inner =  insert_adjacent_state_queue(current,final,visitados,next);
        if(aux_inner != "vazia"){
            cout<<aux<<endl;
            return;
        }
    }
    cout<<"unsolvable"<<endl;

}


int main(){

    int N;
    cin>>N;
    while(N--){
        State puzzle;
        cin>>puzzle.board.tile1>>puzzle.board.tile2>>puzzle.board.tile3>>puzzle.board.tile4>>puzzle.board.tile5>>puzzle.board.tile6>>puzzle.board.tile7>>puzzle.board.tile8>>puzzle.board.tile9;
        //cout<<puzzle.tile1<<puzzle.tile2<<puzzle.tile3<<endl<<puzzle.tile4<<puzzle.tile5<<puzzle.tile6<<endl<<puzzle.tile7<<puzzle.tile8<<puzzle.tile9<<endl;
        puzzle.depth = 0;
        puzzle.moves = "";
        bfs(puzzle);
    }



    return 0;
}