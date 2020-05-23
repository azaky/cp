const
  baslen=8;
  maxlen=10000;
  maxnum=trunc(exp(baslen*ln(10)));

type
  bignum=array[0..maxlen] of int64;

procedure assignnum(str:ansistring; var num:bignum);
  var
    k,len:longint;
    tempnum:string;

  begin
    fillchar(num,sizeof(num),0);
    k:=0;
    while length(str)>baslen do
      begin
        len:=length(str);
        tempnum:=copy(str,len+1-baslen,baslen);
        val(tempnum,num[k]);
        delete(str,len+1-baslen,baslen);
        inc(k);
      end;
    val(str,num[k]);
  end;

procedure print(num:bignum);
  var
    k,i,j:longint;

  begin
    k:=maxlen;
    while (num[k]=0) and (k>0) do dec(k);
    write(num[k]);
    if k=0 then exit;
    for i:=k-1 downto 0 do
      if num[i]=0 then
        for j:=1 to baslen do write(0)
      else
        begin
          for j:=1 to (baslen-1-trunc(ln(num[i])/ln(10))) do write(0);
          write(num[i]);
        end;
  end;

procedure println(num:bignum);
  begin
    print(num);
    writeln;
  end;

function length(num:bignum):longint;
  var
    k:longint;
    
  begin
    k:=maxlen;
    while (num[k]=0) and (k>0) do dec(k);
    if (k=0) and (num[k]=0) then exit(1);
    exit(k*baslen+trunc(ln(num[k])/ln(10))+1);
  end;

function same(num1,num2:bignum):boolean;
  var
    k:longint;
  
  begin
    for k:=0 to maxlen do
      if num1[k]<>num2[k] then exit(false);
    exit(true);
  end;

function more(num1,num2:bignum):boolean;
  var
    k:longint;
  
  begin
    for k:=maxlen downto 0 do
      if num1[k]>num2[k] then exit(true)
        else if num1[k]<num2[k] then exit(false);
    exit(false);
  end;

function less(num1,num2:bignum):boolean;
  var
    k:longint;
  
  begin
    for k:=maxlen downto 0 do
      if num1[k]<num2[k] then exit(true)
        else if num1[k]>num2[k] then exit(false);
    exit(false);
  end;

function sum(num1,num2:bignum):bignum;
  var
    borrow,k:longint;
    tempsum:int64;

  begin
    borrow:=0;
    for k:=0 to maxlen do
      begin
        tempsum:=num1[k]+num2[k]+borrow;
        sum[k]:=tempsum mod maxnum;
        borrow:=tempsum div maxnum;
      end;
  end;

function sub(num1,num2:bignum):bignum;
  var
    k,p,i:longint;
  
  begin
    for k:=0 to maxlen do
      begin
        if num1[k]>=num2[k] then
          begin
            sub[k]:=num1[k]-num2[k];
            continue;
          end
        else p:=k+1;
        while num1[p]=0 do inc(p);
        dec(num1[p]);
        for i:=p-1 downto k+1 do num1[i]:=maxnum-1;
        sub[k]:=num1[k]+maxnum-num2[k];
      end;
  end;

function product(num1,num2:bignum):bignum;
  var
    k1,k2,i1,i2,i:longint;
    tempproduct:int64;

  begin
    fillchar(product,sizeof(product),0);
    k1:=maxlen;
    while (num1[k1]=0) and (k1>0) do dec(k1);
    k2:=maxlen;
    while (num2[k2]=0) and (k2>0) do dec(k2);
    if (num1[k1]=0) or (num2[k2]=0) then exit(product);
    for i1:=0 to k1 do
      for i2:=0 to k2 do
        begin
          tempproduct:=num1[i1]*num2[i2];
          inc(product[i1+i2],(tempproduct mod maxnum));
          inc(product[i1+i2+1],(tempproduct div maxnum));
        end;
    for i:=0 to maxlen-1 do
      begin
        inc(product[i+1],(product[i] div maxnum));
        product[i]:=product[i] mod maxnum;
      end;
  end;

function power(num:bignum; e:longint):bignum;
  var
    temppower:bignum;

  begin
    if e=0 then
      begin
        fillchar(power,sizeof(power),0);
        power[0]:=1;
        exit(power);
      end;
    temppower:=power(num,e div 2);
    temppower:=product(temppower,temppower);
    if e mod 2=1 then temppower:=product(temppower,num);
    exit(temppower);
  end;

function big(n:int64):bignum;
  var
    s:ansistring;
    res:bignum;
  
  begin
    str(n,s);
    assignnum(s,res);
    exit(res);
  end;

operator + (a,b:bignum) res:bignum;
  begin
    res := sum(a,b);
  end;
operator * (a,b:bignum) res:bignum;
  begin
    res := product(a,b);
  end;

var
  s:ansistring;
  n1,n2:bignum;

begin
  readln(s);assignnum(s,n1);
  readln(s);assignnum(s,n2);
  println(n1+n2);
  println(n1*n2);
end.

