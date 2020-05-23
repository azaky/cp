var
  n,k,p,tp,i:longint;
  student:array[1..10001] of string;
  project:array[1..101] of string;
  num:array[1..10001] of longint;
  ans:array[1..101] of longint;

procedure init;
  var
    s:string;
  
  begin
    n:=0; k:=0;
    fillchar(ans,sizeof(ans),0);
    readln(s); if s='0' then halt;
    repeat
      if s[1] in ['A'..'Z'] then
        begin
          inc(n);
          project[n]:=s;
        end
      else
        begin
          inc(k);
          student[k]:=s;
          num[k]:=n;
        end;
      readln(s);
    until (s='1') or (s='0');
    student[k+1]:='';
  end;

procedure sort(l,r:longint);
  var
    i,j,midn,tempn:longint;
    mids,temps:string;
  
  begin
    i:=l; j:=r; mids:=student[(l+r) div 2]; midn:=num[(l+r) div 2];
    repeat
      while (student[i]<mids) or ((student[i]=mids) and (num[i]<midn)) do inc(i);
      while (student[j]>mids) or ((student[j]=mids) and (num[j]>midn)) do dec(j);
      if i>j then break;
      temps:=student[i]; student[i]:=student[j]; student[j]:=temps;
      tempn:=num[i]; num[i]:=num[j]; num[j]:=tempn;
      inc(i); dec(j);
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

procedure sorta(l,r:longint);
  var
    i,j,mida,tempa:longint;
    midp,tempp:string;
  
  begin
    i:=l; j:=r; midp:=project[(l+r) div 2]; mida:=ans[(l+r) div 2];
    repeat
      while (ans[i]>mida) or ((ans[i]=mida) and (project[i]<midp)) do inc(i);
      while (ans[j]<mida) or ((ans[j]=mida) and (project[j]>midp)) do dec(j);
      if i>j then break;
      tempp:=project[i]; project[i]:=project[j]; project[j]:=tempp;
      tempa:=ans[i]; ans[i]:=ans[j]; ans[j]:=tempa;
      inc(i); dec(j);
    until i>j;
    if l<j then sorta(l,j);
    if i<r then sorta(i,r);
  end;

begin
  while true do
    begin
      init;
      sort(1,k);
      p:=0;
      while p<k do
        begin
          inc(p); tp:=p;
          while student[p]=student[tp] do inc(p);
          dec(p);
          if num[p]<>num[tp] then continue
            else inc(ans[num[p]]);
        end;
      //for i:=1 to k do writeln(student[i],' ',num[i]);
      sorta(1,n);
      for i:=1 to n do writeln(project[i],' ',ans[i]);
    end;
end.

