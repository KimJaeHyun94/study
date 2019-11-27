ds <- data.frame(state.x77)
model <- lm(Murder~Illiteracy,ds)
model
coef(model)[1]
coef(model)[2]
Illiteracy <- ds[,"Illiteracy"]
pred <- 2.397*Illiteracy+4.257
pred

Murder <- 2.397*0.5+4.257
Murder
Murder <- 2.397*1.0+4.257
Murder
Murder <- 2.397*1.5+4.257
Murder

library(mlbench)
library(MASS)
head(BostonHousing)
newdata <- BostonHousing[,c(1:14)]
head(newdata)
mod <- lm(medv~., data=newdata)
step <- stepAIC(mod,direction="both")

newdata2 <- BostonHousing[,c(1:14)]
head(newdata2)
mod3 <- lm(medv~crim+zn+chas+nox+rm+dis+rad+tax+ptratio+b+lstat,data=newdata2)
summary(mod3)
crim <- 0.00632
zn <- 18
chas1 <- 0
nox <- 0.538
rm <- 6.575
dis <- 4.0900
rad <- 1
tax <- 296
ptratio <- 15.3
b <- 396.9
lstat <- 4.98
pred <- (-0.108413)*crim+ 0.045845*zn+ 2.718716*chas1 +(-17.376023)*nox+ 3.801579*rm+(-1.492711)*dis+
  0.299608 *rad+(-0.011778)*tax+(-0.946525)*ptratio+0.009291*b+(-0.522553*lstat)+36.341145
pred

setwd("C:/Users/User")
mydata <- read.csv("ucla_admit.csv")
mydata
mod3 <- glm(admit~., data=mydata)
summary(mod3)

test <- mydata[,2:4]
pred <- predict(mod3,test)
pred
pred <- round(pred,0)
pred
pred==mydata[,1]
acc <- mean(pred==mydata[,1])
acc

iris[,-5]
sd <- iris[,-5]
sd
c1 <- kmeans(sd,3)
c1
plot(sd[,2:3],col=c1$cluster)


new.data=scale(state.x77)
c1 <- kmeans(new.data,5)
c1
plot(new.data[,c(1,3)],col=c1$cluster)

setwd("C:/Users/User")
mydata <- read.csv("wdbc.csv")
mydata
require("class")

tr.idx <- c(1)
a <- 2
for( i in 2:568) {
  if(i%%2==1) { 
    tr.idx[a] <- i
    print(i)
    a <- a+1
  }
}
tr.idx
mydata
row(BreastCancer)
ds.tr <- mydata[tr.idx,-c(1:2)]
ds.ts <- mydata[-tr.idx,-c(1:2)]
cl.tr <- factor(mydata[tr.idx,2])
cl.ts <- factor(mydata[-tr.idx,2])

pred <- knn(ds.tr,ds.ts, cl.tr, k=7,prob=TRUE)
acc <- mean(pred==cl.ts)
acc

library(mlbench)
data(BreastCancer)
head(BreastCancer)
nrow(BreastCancer)
BreastCancer
require("class")
group.1 <- cut(seq(1:233),breaks=5,labels=FALSE)
group.2 <- cut(seq(234:466),breaks=5,labels=FALSE)
group.3 <- cut(seq(467:699),breaks=5,labels=FALSE)
fold <- c(group.1,group.2,group.3)

acc <- c()

for(i in 1:10){
  ds.tr <- BreastCancer[fold!=i,2:10]
  ds.ts <- BreastCancer[fold==i,2:10]
  cl.tr <- factor(BreastCancer[fold!=i, "class"])
  cl.ts <- factor(BreastCancer[fold==i, "class"])
  pred <- knn(ds.tr, ds.ts, cl.tr, k=5)
  acc[i] <- mean(pred==cl.ts)
}
acc
mean(acc)


library(mlbench)
nrow(PimaIndiansDiabetes)
data("PimaIndiansDiabetes")
dim(PimaIndiansDiabetes)

group.1 <- cut(seq(1:256),breaks=5,labels=FALSE)
group.2 <- cut(seq(257:512),breaks=5,labels=FALSE)
group.3 <- cut(seq(513:768),breaks=5,labels=FALSE)
fold <- c(group.1,group.2,group.3)

for(i in 1:10){
  ds.tr <- PimaIndiansDiabetes[fold!=i, 1:8]
  ds.ts <- PimaIndiansDiabetes[fold==i, 1:8]
  cl.tr <- factor(PimaIndiansDiabetes[fold!=i, 9])
  cl.ts <- factor(PimaIndiansDiabetes[fold==i, 9])
  pred <- knn(ds.tr, ds.ts, cl.tr, k=5)
  acc[i] <- mean(pred==cl.ts)
}
acc
mean(acc)

library(MASS)
mod3 <- glm(as.integer(diabetes)~ ., data=PimaIndiansDiabetes)
summary(mod3)
test <- PimaIndiansDiabetes[,1:8]
pred <- predict(mod3, test)
pred

pred <- round(pred,0)
pred
pred==as.integer(PimaIndiansDiabetes[,9])
acc <- mean(pred==as.integer(PimaIndiansDiabetes[,9]))
acc


library(caret)
library(ModelMetrics)
library(caret)
fld <- createFolds(PimaIndiansDiabetes$diabetes,k=10)
acc <- c()
for(i in 1:10){
  ds.tr <- PimaIndiansDiabetes[-fld[[i]],1:8]
  ds.ts <- PimaIndiansDiabetes[fld[[i]],1:8]
  cl.tr <- factor(PimaIndiansDiabetes[-fld[[i]], 9])
  cl.ts <- factor(PimaIndiansDiabetes[fld[[i]], 9])
  pred <- knn(ds.tr, ds.ts, cl.tr, k=5)
  acc[i] <- mean(pred==cl.ts)
}
acc
mean(acc)

BreastCancer
library(caret)
fld <- createFolds(BreastCancer$Class,k=10)
acc <- c()
for(i in 1:10){
  ds.tr <- BreastCancer[-fld[[i]],c(2:6,8:10)]
  ds.ts <- BreastCancer[fld[[i]],c(2:6,8:10)]
  cl.tr <- factor(BreastCancer[-fld[[i]], 11])
  cl.ts <- factor(BreastCancer[fld[[i]], 11])
  pred <- knn(ds.tr, ds.ts, cl.tr, k=5)
  acc[i] <- mean(pred==cl.ts)
}
acc
mean(acc)
library(MASS)

test <- BreastCancer[,1:10]
pred <- predict(mod3,test)

pred==as.integer(PimaIndiansDiabetes[,9]))
acc

library(randomForest)
setwd("C:/Users/User")
datasetA <- read.csv("dataset_A.csv")
set.seed(71)
ind <- sample(2,nrow(letters),replace=TRUE,prob=c(0.8,0.2))
iris.rf <- randomForest(letter ~ ., data=letters[ind==1,])
iris.pred <- predict(iris.rf, letters[ind==2,])
acc <- mean(iris.pred==letters[ind==2,5])
acc


liver <- read.csv("liver.csv")

train <- liver[1:300,]
test <- liver[301:345,]
str(liver)
test[,1] <- factor(test[,1])
is.factor(test[,1])
model<- svm(train[,-1],train[,1],kernal="linear")
model
result <- predict(model, test[,-1])
mean(result==test[,1])


letters <- read.csv("letterdata.csv")
str(letters)
letters_train <- letters[1:16000, ]
letters_test <- letters[16001:20000, ]
iris.rf <- randomForest(train[,-1],train[,1])
iris.pred <- predict(iris.rf,test[,-1])
acc<- mean(iris.pred==test[,1])
acc



letters_train[,1] <- factor(letters_train[,1])
model <- svm(letters_train[,-1], letters_train[,1])
model
result <- predict(model,letters_test[,-1])
mean(result == letters_test[,1]) 
nrow(liver)

error_cost <- matrix(c(0,1,4,0),nrow=2)
error_cost
library(caret)
fld <- createFolds(iris$Species,k=5)
fld
ds <- c(1:nrow(iris))
ds

nrow(iris)
iris_rand <- iris[order(runif(150)),]
iris_rand

setwd("C:/Users/User")
mydata <- read.csv("ucla_admit.csv")
mydata
mod3 <- glm(admit~., data=mydata)
summary(mod3)
gre <- mydata[,"gre"]
gpa <- mydata[,"gpa"]
rank <- mydata[,"rank"]
pred <- -0.1824127+0.0004424*gre+
  0.1510402*gpa+
  (-0.1095017)*rank