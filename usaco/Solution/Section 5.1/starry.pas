{
ID: a_zaky01
PROG: starry
LANG: PASCAL
}

type
  cluster=record
    star:array[0..101,0..101] of boolean;
    size,w,h:longint;
  end;

var
  w,h,i,j,k,now:longint;
  input:string;
  new:boolean;
  temp:cluster;
  a,stat:array[0..101,0..101] of boolean;
  ans:array[0..101,0..101] of byte;
  seen:array[1..26] of cluster;
  fin,fout:text;

function gen(i,j:integer):cluster;
  var
    i0,j0,minh,maxh,minw,maxw:integer;

  procedure fill(i,j:integer);
    var
      i1,j1:integer;

    begin
      stat[i,j]:=true;
      inc(gen.size);
      if i<minh then minh:=i;
      if i>maxh then maxh:=i;
      if j<minw then minw:=j;
      if j>maxw then maxw:=j;
      for i1:=i-1 to i+1 do
        for j1:=j-1 to j+1 do
          if not ((i1=1) and (j1=j)) then
            if a[i1,j1] and not stat[i1,j1] then fill(i1,j1);
    end;

  begin
    with gen do
      begin
        size:=0;
        fillchar(star,sizeof(star),false);
      end;
    minh:=i;
    maxh:=i;
    minw:=j;
    maxw:=j;
    fill(i,j);
    dec(minh);
    dec(minw);
    gen.h:=maxh-minh;
    gen.w:=maxw-minw;
    for i0:=1 to gen.h do
      for j0:=1 to gen.w do
        if stat[i0+minh,j0+minw] and (ans[i0+minh,j0+minw]=0) then
          gen.star[i0,j0]:=true;
  end;

procedure fill(i,j,k:integer);
  var
    i1,j1:integer;

  begin
    ans[i,j]:=k;
    for i1:=i-1 to i+1 do
      for j1:=j-1 to j+1 do
        if not ((i1=1) and (j1=j)) then
          if a[i1,j1] and (ans[i1,j1]<>k) then fill(i1,j1,k);
  end;

function match(cl1,cl2:cluster):boolean;
  var
    i,j:integer;
    temp:cluster;

  function check:boolean;
    var
      i,j,h0,w0:integer;

    function same:boolean;
      var
        i,j:integer;

      begin
        for i:=1 to h0 do
          for j:=1 to w0 do
            if cl1.star[i,j] xor cl2.star[i,j] then exit(false);
        exit(true);
      end;

    procedure swap(var a,b:boolean);
      var
        temp:boolean;

      begin
        temp:=a;
        a:=b;
        b:=temp;
      end;

    begin
      if cl1.h<>cl2.h then exit(false);
      h0:=cl1.h;
      w0:=cl1.w;
      if same then exit(true);
      for i:=1 to h0 do
        for j:=1 to w0 div 2 do
          swap(cl1.star[i,j],cl1.star[i,w0-j+1]);
      if same then exit(true);
      for i:=1 to h0 div 2 do
        for j:=1 to w0 do
          swap(cl1.star[i,j],cl1.star[h0-i+1,j]);
      if same then exit(true);
      for i:=1 to h0 do
        for j:=1 to w0 div 2 do
          swap(cl1.star[i,j],cl1.star[i,w0-j+1]);
      if same then exit(true);
      exit(false);
    end;

  begin
    if cl1.size<>cl2.size then exit(false);
    if cl1.w*cl1.h<>cl2.w*cl2.h then exit(false);
    if (cl1.w<>cl2.w) and (cl1.w<>cl2.h) then exit(false);
    if check then exit(true);
    temp:=cl1;
    for i:=1 to cl1.w do
      for j:=1 to cl1.h do
        temp.star[i,j]:=cl1.star[j,i];
    temp.w:=cl1.h;
    temp.h:=cl1.w;
    cl1:=temp;
    if check then exit(true);
    exit(false);
  end;

begin
  assign(fin,'starry.in');
  assign(fout,'starry.out');
  reset(fin);
  rewrite(fout);
  readln(fin,w,h);
  for i:=1 to h do
    begin
      readln(fin,input);
      for j:=1 to w do
        if input[j]='1' then a[i,j]:=true;
    end;
  now:=0;
  for i:=1 to h do
    for j:=1 to w do
      if a[i,j] and not stat[i,j] then
        begin
          temp:=gen(i,j);
          new:=true;
          for k:=1 to now do
            if match(temp,seen[k]) then
              begin
                fill(i,j,k);
                new:=false;
                break;
              end;
          if new then
            begin
              inc(now);
              fill(i,j,now);
              seen[now]:=temp;
            end;
        end;
  for i:=1 to h do
    begin
      for j:=1 to w do
        if ans[i,j]=0 then write(fout,0)
          else write(fout,chr(ans[i,j]+96));
      writeln(fout);
    end;
  close(fin);
  close(fout);
end.
