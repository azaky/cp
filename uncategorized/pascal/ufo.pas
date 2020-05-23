var
  text1,text2:string;
  product1,product2,i,diff:longint;
  _:array[a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z] of integer;

begin
  readln(text1);
  readln(text2);
  product1:=1;
  product2:=2;
  _[a]:=1; _[b]:=2; _[c]:=3; _[d]:=4; _[e]:=5; _[f]:=6; _[g]:=7; _[h]:=8; _[i]:=9; _[j]:=10; _[k]:=11; _[l]:=12; _[m]:=13; _[n]:=14; _[o]:=15; _[p]:=16; _[q]:=17; _[r]:=18; _[s]:=19; _[t]:=20; _[u]:=21; _[v]:=22; _[w]:=23; _[x]:=24; _[y]:=25; _[z]:=26;
  for i:= to length(text1) do product1:=product1*_[text1[i]];
  for i:= to length(text2) do product2:=product2*_[text2[i]];
  diff:=product1-product2;
  if diff mod 47=0 then writeln('GO') else writeln('STAY');
end.