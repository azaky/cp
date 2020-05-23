var
  n,i,max,cur,flag:longint;
  k,word:array[1..10001] of string;
  best,curbest:string;

function sorted(t:string):string;
  var
    s:string;
     
  procedure sort(l,r:integer);
    var
      i,j:integer;
      mid,temp:char;
     
    begin
      i:=l; j:=r; mid:=s[(l+r) div 2];
      repeat
        while s[i]<mid do inc(i);
        while s[j]>mid do dec(j);
        if i>j then break;
        temp:=s[i]; s[i]:=s[j]; s[j]:=temp;
        inc(i); dec(j);
      until i>j;
      if l<j then sort(l,j);
      if i<r then sort(i,r);
    end;
   
  begin
    s:=t;
    sort(1,length(s));
    exit(s);
  end;

procedure sort(l,r:longint);
  var
    i,j:longint;
    midk,midw,temp:string;
  
  begin
    i:=l; j:=r; midk:=k[(l+r) div 2]; midw:=word[(l+r) div 2];
    repeat
      while (k[i]<midk) or ((k[i]=midk) and (word[i]<midw)) do inc(i);
      while (k[j]>midk) or ((k[j]=midk) and (word[j]>midw)) do dec(j);
      if i>j then break;
      temp:=k[i]; k[i]:=k[j]; k[j]:=temp;
      temp:=word[i]; word[i]:=word[j]; word[j]:=temp;
      inc(i); dec(j);
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  readln(n);
  for i:=1 to n do
    begin
      readln(word[i]);
      k[i]:=sorted(word[i]);
    end;
  sort(1,n); k[n+1]:='!@#$%^&*()';
  max:=1; cur:=1; best:=word[1]; curbest:=word[1]; flag:=1;
  for i:=2 to n+1 do
    if k[i]=k[i-1] then inc(cur)
      else
        begin
          if (cur>max) or ((cur=max) and (curbest<best)) then
            begin
              max:=cur; best:=curbest; flag:=i-max;
            end;
          cur:=1; curbest:=word[i];
        end;
  if max=1 then writeln('TIDAK ADA')
    else
      begin
        writeln(max);
        for i:=flag to flag+max-1 do writeln(word[i]);
      end;
end.

