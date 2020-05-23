procedure error; begin writeln(-1); halt; end;

const
  ax1 = 'abbb'; ay1 = 'aabb';
  ax2 = 'babb'; ay2 = 'abab';
  ax3 = 'bbab'; ay3 = 'abba';
  ax4 = 'bbba';

var
  i,j,length,x,x1,x2,x3,x4,y1,y2,y3,ansx,ansy1,ansy2,ansy3:longint;
  h:array[0..4,0..4] of longint;
  s:array[0..4] of ansistring;
  valid:boolean;

begin
  read(h[1][2],h[1][3],h[1][4],h[2][3],h[2][4],h[3][4]);
  length := maxlongint;
  for y1 := 0 to 600000 do
    begin
      y3 := 2*y1 + h[1][2]+h[3][4]-h[2][3]-h[1][4];
      if (y3 mod 2=1) or (y3<0) then continue else y3 := y3 shr 1;
      x  := h[1][3]+h[2][4] - 2*(y1+y3);
      if (x<0) then continue;
      y2 := h[2][3]+h[1][4]- x -2*y1;
      if (y2 mod 2=1) or (y2<0) then continue else y2 := y2 shr 1;
      if h[1][2]<y2+y3 then continue;
      if h[3][4]<y2+y3 then continue;
      if h[2][3]<y1+y2 then continue;
      if h[1][4]<y1+y2 then continue;
      if h[1][3]<y1+y3 then continue;
      if h[2][4]<y1+y3 then continue;
      x1 := h[1][2]+h[3][4]-2*(y2+y3);
      x2 := h[2][3]+h[1][4]-2*(y1+y2);
      x3 := h[1][3]+h[2][4]-2*(y1+y3);
      if (x1<>x2) or (x1<>x3) or (x2<>x3) then continue;
      if x+y1+y2+y3 < length then
        begin
          length := x+y1+y2+y3;
          ansx := x; ansy1 := y1; ansy2 := y2; ansy3 := y3;
        end;
    end;
  if length=maxlongint then error;
  x := ansx; y1 := ansy1; y2 := ansy2; y3 := ansy3;
  //writeln(x,' ',y1,' ',y2,' ',y3);
  for x1:=0 to x do
    begin
      x2 := h[1][2]-y2-y3-x1;
      x3 := h[1][3]-y1-y3-x1;
      x4 := h[1][4]-y1-y2-x1;
      if (x2>=0) and (x3>=0) and (x4>=0) {and (x1+x2+x3+x4=x)} then
        begin
          for i:=1 to 4 do s[i]:='';
          for i:=1 to 4 do
            begin
              for j:=1 to x1 do s[i]:=s[i]+ax1[i];
              for j:=1 to x2 do s[i]:=s[i]+ax2[i];
              for j:=1 to x3 do s[i]:=s[i]+ax3[i];
              for j:=1 to x4 do s[i]:=s[i]+ax4[i];
              for j:=1 to y1 do s[i]:=s[i]+ay1[i];
              for j:=1 to y2 do s[i]:=s[i]+ay2[i];
              for j:=1 to y3 do s[i]:=s[i]+ay3[i];
            end;
          writeln(length);
          for i:=1 to 4 do writeln(s[i]);
          halt;
        end;
    end;
  error;
end.
