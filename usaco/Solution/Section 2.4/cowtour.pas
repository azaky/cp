{
ID: a_zaky01
PROG: cowtour
LANG: PASCAL
}

const
  infinity=99999999.999999;

type
  point=record
          x,y:longint;
        end;
  past=array[1..150] of integer;

var
  n,i,j,k,l,i1,j1,i2,j2:longint;
  ans,diai,diaj,dia,diai0,diaj0,min:real;
  input:string;
  p:array[1..150] of point;
  connected:array[1..150,1..150] of boolean;
  used:array[1..150] of boolean;
  pastures:array[1..150] of past;
  size:array[1..150] of integer;
  d,leni,lenj:array[1..150,1..150] of real;
  fin,fout:text;

function distance(p1,p2:point):real;
  begin
    distance:=sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
  end;

procedure floodfill(pos:integer);
  var
    i:integer;

  begin
    inc(j);
    used[pos]:=true;
    pastures[k][j]:=pos;
    for i:=1 to n do
      if not(used[i]) and (connected[pos,i]) then floodfill(i);
  end;

begin
  assign(fin,'cowtour.in');
  assign(fout,'cowtour.out');
  reset(fin);
  rewrite(fout);
  readln(fin,n);
  for i:=1 to n do
    for j:=1 to n do d[i,j]:=infinity;
  for i:=1 to n do readln(fin,p[i].x,p[i].y);
  for i:=1 to n do
    begin
      readln(fin,input);
      for j:=1 to n do
        if input[j]='1' then
          begin
            connected[i,j]:=true;
            d[i,j]:=distance(p[i],p[j]);
          end;
    end;
  k:=0;
  for i:=1 to n do
    if not used[i] then
      begin
        inc(k);
        j:=0;
        floodfill(i);
        size[k]:=j;
      end;
  ans:=0;
  for i1:=1 to k-1 do
    for j1:=i1+1 to k do
      begin
        for i:=1 to size[i1] do
          for j:=1 to size[i1] do
            if (d[pastures[i1][i],pastures[i1][j]]=0) {and (i<>j)} then leni[i,j]:=infinity
              else leni[i,j]:=d[pastures[i1][i],pastures[i1][j]];
        for l:=1 to size[i1] do
          for i:=1 to size[i1] do
            for j:=1 to size[i1] do
              if leni[i,l]+leni[l,j]<leni[i,j] then
                leni[i,j]:=leni[i,l]+leni[l,j];
        for i:=1 to size[i1] do leni[i,i]:=0;
        diai0:=0;
        for i:=1 to size[i1] do
          for j:=1 to size[i1] do 
            if leni[i,j]>diai0 then diai0:=leni[i,j];
        for i:=1 to size[j1] do
          for j:=1 to size[j1] do
            if (d[pastures[j1][i],pastures[j1][j]]=0) {and (i<>j)} then lenj[i,j]:=infinity
              else lenj[i,j]:=d[pastures[j1][i],pastures[j1][j]];
        for l:=1 to size[j1] do
          for i:=1 to size[j1] do
            for j:=1 to size[j1] do
              if lenj[i,l]+lenj[l,j]<lenj[i,j] then
                lenj[i,j]:=lenj[i,l]+lenj[l,j];
        for i:=1 to size[j1] do lenj[i,i]:=0;
        diaj0:=0;
        for i:=1 to size[j1] do
          for j:=1 to size[j1] do 
            if lenj[i,j]>diaj0 then diaj0:=lenj[i,j];
        for i:=1 to size[i1] do
          for j:=1 to size[j1] do
            begin
              dia:=distance(p[pastures[i1][i]],p[pastures[j1][j]]);
              diai:=0;
              for i2:=1 to size[i1] do
                if leni[i,i2]>diai then diai:=leni[i,i2];
              diaj:=0;
              for j2:=1 to size[j1] do
                if lenj[j,j2]>diaj then diaj:=lenj[j,j2];
              if (diai0>=diaj0) and (diai0>=dia+diai+diaj) then min:=diai0
                else if (diaj0>=diai0) and (diaj0>=dia+diai+diaj) then min:=diaj0
                  else min:=dia+diai+diaj;
              if (ans=0) or (ans>min) then ans:=min;
            end;
      end;
  writeln(fout,ans:0:6);
  close(fin);
  close(fout);
end.
