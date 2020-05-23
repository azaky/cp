{
ID: a_zaky01
PROG: frameup
LANG: PASCAL
}

var
  h,w,i,j,n,totalans:longint;
  ch,up,dw,ch2:char;
  input:string;
  valid,found:boolean;
  a:array[1..30,1..30] of char;
  exist:array['A'..'Z'] of boolean;
  minh,minw,maxh,maxw:array['A'..'Z'] of longint;
  con:array['A'..'Z','A'..'Z'] of boolean;
  ans:array[1..10000] of string;
  fin,fout:text;

procedure find(str:string);
  var
    ch,ch2:char;

  begin
    if length(str)=n then
      begin
        inc(totalans);
        ans[totalans]:=str;
        exit;
      end;
    for ch:='A' to 'Z' do
      if exist[ch] then
        begin
          valid:=true;
          for ch2:='A' to 'Z' do
            if exist[ch2] then
              if con[ch2,ch] then
                begin
                  valid:=false;
                  break;
                end;
          if valid then
            begin
              exist[ch]:=false;
              find(ch+str);
              exist[ch]:=true;
            end;
        end;
  end;

procedure sort(l,r:longint);
  var
    i,j:longint;
    temp,mid:string;

  begin
    i:=l;
    j:=r;
    mid:=ans[(l+r) div 2];
    repeat
      while ans[i]<mid do inc(i);
      while ans[j]>mid do dec(j);
      if i<=j then
        begin
          temp:=ans[i];
          ans[i]:=ans[j];
          ans[j]:=temp;
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  assign(fin,'frameup.in');
  assign(fout,'frameup.out');
  reset(fin);
  rewrite(fout);
  readln(fin,h,w);
  for i:=1 to h do
    begin
      readln(fin,input);
      for j:=1 to w do
        begin
          a[i,j]:=input[j];
          if a[i,j]<>'.' then exist[a[i,j]]:=true;
        end;
    end;
  for ch:='A' to 'Z' do
    if exist[ch] then
      begin
        minh[ch]:=h;
        minw[ch]:=w;
        maxh[ch]:=1;
        maxw[ch]:=1;
        inc(n);
      end;
  for i:=1 to h do
    for j:=1 to w do
      if a[i,j]<>'.' then
        begin
          ch:=a[i,j];
          if i>maxh[ch] then maxh[ch]:=i;
          if i<minh[ch] then minh[ch]:=i;
          if j>maxw[ch] then maxw[ch]:=j;
          if j<minw[ch] then minw[ch]:=j;
        end;
  for ch:='A' to 'Z' do
    if exist[ch] then
      begin
        for i:=minh[ch] to maxh[ch] do
          begin
            up:=a[i,minw[ch]];
            dw:=a[i,maxw[ch]];
            if not ((up=ch) or (up='.')) then con[up,ch]:=true;
            if not ((dw=ch) or (dw='.')) then con[dw,ch]:=true;
          end;
        for j:=minw[ch]+1 to maxw[ch]-1 do
          begin
            up:=a[minh[ch],j];
            dw:=a[maxh[ch],j];
            if not ((up=ch) or (up='.')) then con[up,ch]:=true;
            if not ((dw=ch) or (dw='.')) then con[dw,ch]:=true;
          end;
      end;
  find('');
  sort(1,totalans);
  for i:=1 to totalans do writeln(fout,ans[i]);
  close(fin);
  close(fout);
end.
