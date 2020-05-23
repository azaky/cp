uses math;

var
  n,m,i,j,size,ans:longint;
  a,sumr,sumc:array[0..555,0..555] of longint;
  total,temp:array[0..555,0..555,1..4] of longint;

begin
  readln(n,m); ans:=-1111111111;
  for i:=1 to n do
    for j:=1 to m do read(a[i,j]);
  fillchar(sumr,sizeof(sumr),0);
  fillchar(sumc,sizeof(sumc),0);
  for i:=1 to n do
    for j:=1 to m do sumr[i][j]:=sumr[i][j-1]+a[i,j];
  for i:=1 to m do
    for j:=1 to n do sumc[i][j]:=sumc[i][j-1]+a[j,i];
  //size1
  for i:=1 to n do
    for j:=1 to m do total[i,j][1]:=a[i,j];
  //size3
  for i:=1 to n-2 do
    for j:=1 to m-2 do
      begin
        total[i,j][3]:=sumr[i][j+2]-sumr[i][j-1]+sumr[i+2][j+2]-sumr[i+2][j-1]+a[i+1][j+2];
        if total[i,j][3]>ans then ans:=total[i,j][3];
      end;
  for size:=5 to min(n,m) do
    begin
      if size mod 2=0 then continue;
      for i:=3 to n-size+3 do
        for j:=3 to m-size+3 do
          begin
            temp[i,j][1]:=total[i,j][1]; temp[i,j][3]:=total[i,j][3];
          end;
      for i:=1 to n-size+1 do
        for j:=1 to m-size+1 do
          begin
            //writeln(total[i,j][size mod 4]);
            total[i,j][size mod 4]:=temp[i+2,j+2][size mod 4]+(sumr[i][j+size-1]-sumr[i][j-1])+(sumc[j+size-1][i+size-1]-sumc[j+size-1][i])+(sumr[i+size-1][j+size-2]-sumr[i+size-1][j-1])+(sumc[j][i+size-2]-sumc[j][i+1])+a[i+2,j+1];
            if total[i,j][size mod 4]>=ans then ans:=total[i,j][size mod 4];
            //writeln(i,' ',j,' ',size,' ',total[i,j][size mod 4]);
          end;
    end;
  writeln(ans);
end.
