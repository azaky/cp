type
  arr=array[0..6] of longint;

const
  x = -1;

var
  c,i,times,worst,sum,wrong,temp,tc:longint;
  same:boolean;
  num,a,ans,counterexample:arr;
{
function minta(a:arr):longint;
  var
    i:longint;
  
  begin
    minta:=0;
    for i:=1 to 6 do
      if a[i]=num[i] then inc(minta);
    inc(times);
    
    //write('? ');
    //for i:=1 to 6 do write(a[i]);
    //writeln('   ',minta);
    
  end;
}
function minta(a:arr):longint;
  var
    i:longint;
  
  begin
    write('? ');
    for i:=1 to 6 do write(a[i]);
    writeln;
    flush(output);
    readln(minta);
  end;

function main:arr;
  var
    i,last,k,cur,goal,j,sure:longint;
    a:arr;
    impossible:array[0..6,0..9] of boolean;
  
  begin
    for i:=1 to 6 do a[i]:=random(10);
    for i:=0 to 6 do ans[i]:=x;
    fillchar(impossible,sizeof(impossible),false);
    last:=6;
    while last>0 do
      begin
        for i:=1 to 6 do a[i]:=(a[i]+1) mod 10;
        k:=minta(a);
        cur:=k; goal:=k;
        for i:=1 to 6 do
          if a[i]=ans[i] then dec(goal);
        if goal>0 then
          for i:=1 to 6 do
            begin
              if ans[i]<>x then continue;
              a[i]:=(a[i]+1) mod 10;
              if i=last then
                begin
                  ans[i]:=(a[i]+9) mod 10;
    //for j:=1 to 6 do
      //if ans[j]=x then write('x') else write(ans[j]);writeln(' ',k,' ',cur);
                  while ans[last]<>x do dec(last);
                  break;
                end;
              k:=minta(a);
              if k>cur then ans[i]:=a[i]
                else if k=cur then
                  begin
                    impossible[i][a[i]]:=true;
                    impossible[i][(a[i]+9) mod 10]:=true;
                  end
                else if k<cur then
                  begin
                    ans[i]:=(a[i]+9) mod 10;
    //for j:=1 to 6 do
      //if ans[j]=x then write('x') else write(ans[j]);writeln(' ',k,' ',cur);
                    dec(goal);
                    if goal=0 then break;
                  end;
    //for j:=1 to 6 do
      //if ans[j]=x then write('x') else write(ans[j]);writeln(' ',k,' ',cur);
              cur:=k;
            end
        else for i:=1 to 6 do impossible[i][a[i]]:=true;
        
        for i:=1 to 6 do
          begin
            if ans[i]<>x then continue;
            for sure:=0 to 9 do
              if not impossible[i][sure] then break;
            for j:=sure+1 to 9 do
              if not impossible[i][j] then sure:=x;
            if sure<0 then break;
            ans[i]:=sure;
            while ans[last]<>x do dec(last);
          end;
        
      end;

    write('! ');
    for i:=1 to 6 do write(ans[i]);
    writeln;

    exit(ans);
  end;

begin
  randomize;
  a:=main; halt;
  worst:=0; sum:=0; tc:=random(100)+100;
  for c:=1 to 1 do
    begin
      for i:=1 to 6 do num[i]:=random(10);
      //for i:=1 to 6 do read(num[i]);//149949
      {
      temp:=c;
      for i:=1 to 6 do
        begin
          num[7-i]:=temp mod 10;
          temp:=temp div 10;
        end;
      }
      times:=0;
      a:=main;
      same:=true;
      for i:=1 to 6 do
        if num[i]<>a[i] then same:=false;
      {
      writeln('Case #',c);
      write(same:10,'  ');
      for i:=1 to 6 do write(num[i]);
      write('  ');
      for i:=1 to 6 do write(a[i]);
      writeln('  ',times,' asks');
      }
      if times>worst then
        begin
          worst:=times;
          counterexample:=num;
        end;
      sum:=sum+times;
      if not same then inc(wrong);
    end;
  writeln(tc,' test cases');
  writeln('succeed = ',tc-wrong);
  writeln('wrong   = ',wrong);
  write('worst   = ',worst,' for case ');
  for i:=1 to 6 do write(counterexample[i]); writeln;
  writeln('average = ',sum/tc:0:6);

end.

