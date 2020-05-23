{
ID: a_zaky01
PROG: llang
LANG: PASCAL
}

const
  maxm = 30000;
  maxc = 10000;
  maxl = 100010;

var
  m,n,i,j,x,temp,pos,nans:longint;
  k:array[0..maxc] of longint;
  lang,z,c:array[0..maxl] of longint;
  p,ans:array[0..maxm] of longint;
  visit:array[0..maxc] of boolean;
  can,used:array[0..maxm] of boolean;

procedure sort(l,r:longint);
  var
    i,j,zmid,cmid,temp:longint;
  
  begin
    i:=l; j:=r; zmid:=z[(l+r) div 2]; cmid:=c[(l+r) div 2];
    repeat
      while (z[i]<zmid) or ((z[i]=zmid) and (c[i]<cmid)) do inc(i);
      while (z[j]>zmid) or ((z[j]=zmid) and (c[j]>cmid)) do dec(j);
      if i>j then break;
      temp:=z[i]; z[i]:=z[j]; z[j]:=temp;
      temp:=c[i]; c[i]:=c[j]; c[j]:=temp;
      inc(i); dec(j);
    until false;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

procedure add(v:longint);
  var
    w,i,j,x,pos:longint;
    change:boolean;
    a,temp:array[1..maxm] of longint;
  
  begin
  if can[v] then exit;
  a[1]:=v; w:=1;
  
  while true do
    begin
      change:=false; pos:=0;
      for i:=1 to w do
        if not can[a[i]] then
          begin
            change:=true; can[a[i]]:=true;// writeln(a[i]);
            for j:=p[a[i]-1]+1 to p[a[i]] do
              if not visit[c[j]] then
                begin
                  visit[c[j]]:=true;
                  for x:=k[c[j]-1]+1 to k[c[j]] do
                    if not can[lang[x]] then
                      begin
                        inc(pos);
                        temp[pos]:=lang[x];
                      end;
                end;
          end;
      if not change or (pos=0) then break;
      for i:=1 to pos do a[i]:=temp[i];
      w:=pos;
    end;
    
  end;

begin
  assign(input,'llang.in'); reset(input);
  assign(output,'llang.out'); rewrite(output);

  readln(n,m);

  for i:=1 to n do
    begin
      read(k[i]);
      for j:=1 to k[i] do
        begin
          read(temp);
          lang[k[i-1]+j]:=temp;
          z[k[i-1]+j]:=temp; c[k[i-1]+j]:=i;
          used[temp]:=true;
        end;
      k[i]:=k[i]+k[i-1];
    end;
  
  sort(1,k[n]);
  pos:=0;
  for i:=1 to k[n] do
    if z[i]<>z[i-1] then
      while pos<>z[i] do
        begin
          p[pos]:=i-1;
          inc(pos);
        end;
  
  visit[1]:=true;
  for i:=1 to k[1] do add(lang[i]);
  
  nans:=0;
  for i:=1 to m do
    if not can[i] and used[i] then
      begin
        inc(nans); ans[nans]:=i;
        add(i);
      end;
  
  writeln(nans);
  for i:=1 to nans do writeln(ans[i],' 1');
  
  close(input);
  close(output);
end.
