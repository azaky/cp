const
  maxn = 100; //maksimum dari n
  maxk = 100; //maksimum dari k
  maxq = 1000000; //maksimum dari queuenya
                  //ngitungnya: itung aja size dari flagnya
                  //soalnya maksimum size queuenya kan segede size maksimum flagnya
  next : array[1..8,1..2] of integer
       = ((1,2),(2,1),(-1,2),(2,-1),(1,-2),(-2,1),(-1,-2),(-2,-1));
       //ini array buat nentuin posisi berikutnya dari si kuda

var
  x,y,n,k,i,j,nextx,nexty,nextk:integer;
  qtake,qsave:longint;
  queue:array[1..maxq,1..3] of integer;
  flag:array[1..maxn,1..maxn,1..maxk] of boolean;

begin
  //baca input *anaktkjugatau
  readln(x,y,n,k);
  
  //fillchar array flag
  fillchar(flag,sizeof(flag),false);
  
  //qtake = indeks queue yang akan diproses
  qtake:=1;
  
  //qsave = indeks queue yang akan disimpan
  qsave:=1;
  
  //queue[i][1] dan queue[i][2] = posisi kuda
  queue[1][1]:=x; queue[1][2]:=y;
  
  //queue[i][3] = langkah yang dibutuhkan kuda
  queue[1][3]:=0;
  
  //BFS itu kayak gini
  //pseudocode:
  //from the current state: generate all possible next states and put all of them into the queue
  //call the next state
  //repeat the procedure until the the number of states called is more than the size of the queue
  //
  //it's just that simple!
  //
  //implementasinya sebagai berikut:
  repeat
    //nextk = langkah untuk queue berikutnya
    nextk:=queue[qtake][3]+1;
    
    //cek semua kemungkinan langkah kuda berikutnya
    for i:=1 to 8 do
      begin
        //kalo langkahnya udah lebih dari k, break aja
        //tapi ngga boleh break while yang diluar
        //karena bisa aja ada queue yang belom diproses
        if nextk>k then break;
        
        //nextx,nexty = posisi kuda berikutnya
        nextx:=queue[qtake][1]+next[i][1];
        nexty:=queue[qtake][2]+next[i][2];
        
        //cek nextx,nexty masih di dalam papan catur apa ngga
        if (nextx<1) or (nexty<1) or (nextx>n) or (nexty>n) then continue;
        
        //cek apa kondisi ini udah pernah dilewatin/disimpan
        if flag[nextx][nexty][nextk] then continue;
        
        //nah, sekarang karena kondisi ini belum pernah dilewatin,
        //kondisi ini disave di queue berikutnya
        inc(qsave);
        queue[qsave][1]:=nextx;
        queue[qsave][2]:=nexty;
        queue[qsave][3]:=nextk;
        flag[nextx][nexty][nextk]:=true;
      end;
    
    //panggil queue berikutnya
    inc(qtake);
  until qtake>qsave;
  
  //sekarang, tinggal diprint
  //perhatikan bahwa kalau flag[x][y][k] true, berarti bisa mencapai
  //petak (x,y) dalam k langkah
  //biar outputnya langsung keurut, tinggal diloop aja berdasarkan kolom dan barisnya
  for i:=1 to n do
    for j:=1 to n do
      if flag[i][j][k] then writeln(i,' ',j);
  
  //done!
  //worst complexity = when the queue array is full = O(N^2*K)
  //however, that case is impossible and the program will run faster
  
end.

