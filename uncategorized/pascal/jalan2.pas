var
  t,kasus,size,tot,n,m,i,j,k,a,b,next:longint;
  x,y:array[1..1000] of int64;
  deg,ep1,ep2,g,s:array[1..1000] of integer;
  z:array[0..2005] of integer;
  //x,y,deg,z,g,ep1,ep2,s:array[0..4005] of longint;
  visit:array[1..1000] of boolean;
  min:array[1..1000] of extended;
  ans,best,temp:extended;
  
procedure fill(v:integer);
  var
    i:integer;
    
  begin
    if visit[v] then exit;
    visit[v]:=true;
    inc(tot); g[tot]:=v;
    for i:=deg[v]+1 to deg[v+1] do fill(z[i]);
  end;

function dis(a,b:integer):extended;
  begin
    dis:=sqrt( sqr(x[a]-x[b])+sqr(y[a]-y[b]) );
  end;

begin
{
assign(input,'jalan.txt');
assign(output,'jalan.out');
reset(input);
rewrite(output);
}
  readln(t);
  for kasus:=1 to t do
    begin
      fillchar(deg,sizeof(deg),0);
      fillchar(visit,sizeof(visit),false);
      fillchar(s,sizeof(s),0);
      size:=0;
      tot:=0;
      ans:=0.00;
      
      readln(n,m);
      
      for i:=1 to n do readln(x[i],y[i]);
      
      for i:=1 to m do
        begin
          readln(a,b);
          ep1[i]:=a; ep2[i]:=b;
          inc(deg[a]); inc(deg[b]);
        end;
      
      for i:=2 to n+1 do deg[i]:=deg[i]+deg[i-1];
      
      for i:=1 to m do
        begin
          a:=ep1[i]; b:=ep2[i];
          z[deg[a]]:=b; z[deg[b]]:=a;
          dec(deg[a]); dec(deg[b]);
        end;
      
      for i:=1 to n do
        if not visit[i] then
          begin
            inc(size);
            fill(i);
            s[size+1]:=tot;
          end;
      
      for i:=1 to size do min[i]:=-1.00;
      for i:=2 to size do
        for j:=s[1]+1 to s[2] do 
          for k:=s[i]+1 to s[i+1] do
            begin
              temp:=dis(g[j],g[k]);
              if (min[i]<0) or (min[i]>temp) then min[i]:=temp;
            end;
      
      fillchar(visit,sizeof(visit),false);
      visit[1]:=true;
      while true do
        begin
          next:=-1; best:=1e50;
          for i:=2 to size do
            if not visit[i] then
              if min[i]<best then
                begin
                  next:=i; best:=min[i];
                end;
          
          if next=-1 then break;
          
          visit[next]:=true;
          ans:=ans+min[next];
          
          for i:=2 to size do
            if not visit[i] then
              for j:=s[next]+1 to s[next+1] do
                for k:=s[i]+1 to s[i+1] do
                  begin
                    temp:=dis(g[j],g[k]);
                    if min[i]>temp then min[i]:=temp;
                  end;
        end;
      
      writeln((trunc(100*ans)/100):0:2);
      
      //complexity: O(N) (flood fill) + O(N^2) (MST)
      
    end;
{
close(input);
close(output);
}
end.

