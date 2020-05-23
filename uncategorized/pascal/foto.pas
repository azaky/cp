const
  max = round(1e18);

var
  n,m,k,d,i,j,z,a,b,vis,ans:longint;
  wi,best:int64;
  con:array[1..50,1..50] of boolean;
  can:array[1..50] of boolean;
  sesi:array[1..50] of integer;
  w,time:array[1..50,1..50] of int64;

function min(a,b:int64):int64;
  begin
    if a<b then exit(a)
      else exit(b);
  end;

begin
  for i:=1 to n do
    for j:=1 to n do
      if i=j then w[i,j]:=0
        else w[i,j]:=max;
  fillchar(can,sizeof(can),false);
        
  readln(n,m,k,d);
  
  for i:=1 to m do
    begin
      readln(a,b,wi);
      if con[a,b] then
        begin
          w[a,b]:=min(w[a,b],wi);
          w[b,a]:=w[a,b];
        end
      else
        begin
          con[a,b]:=true; con[b,a]:=true;
          w[a,b]:=wi; w[b,a]:=wi;
        end;
    end;
  
  //floyd warshall algorithm
  for z:=1 to n do
    for i:=1 to n do
      for j:=1 to n do
        if w[i,j]>w[i,z]+w[z,j] then w[i,j]:=w[i,z]+w[z,j];
  {
  for i:=1 to n do
    begin
      for j:=1 to n do write(w[i,j]:5);
      writeln;
    end;
  writeln;
  }
  for i:=1 to k do readln(sesi[i]);
  
  //define an array time[z,vis] is the minimum time for you to join z-th session
  //where the z-th session is the vis-th session that is already visited
  
  fillchar(time,sizeof(time),255);
  fillchar(can,sizeof(can),false);
  
  for i:=1 to k do
    if 1+w[1,sesi[i]]<=d*i then
      begin
        time[i,1]:=1+w[1,sesi[i]];
        if time[i,1]<1+d*(i-1) then time[i,1]:=1+d*(i-1);
        can[1]:=true;
      end;
  
  for vis:=2 to k do
    if can[vis-1] then
      for z:=vis to k do
        begin
          best:=max;
          for j:=1 to z-1 do
            if (time[j,vis-1]>0) and (time[j,vis-1]+w[sesi[z],sesi[j]]<best) then
              best:=time[j,vis-1]+w[sesi[z],sesi[j]];
          if best<=d*z then
            begin
              can[vis]:=true;
              if best<1+d*(z-1) then best:=1+d*(z-1);
              time[z,vis]:=best;
            end;
        end;
  {
  for i:=1 to k do
    begin
      for j:=1 to k do write(time[i,j]:5);
      writeln;
    end;
  }
  ans:=0;
  for i:=1 to k do
    if can[i] then ans:=i;
  writeln(ans);
  
end.

