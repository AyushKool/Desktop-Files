library(ggplot2)

df <-
  read.csv(
    'C:/Users/ayush/Desktop/Python/Imputation Methods/Final DS/Error/NRMSE.csv',
    check.names = F
  )
ds <- as.data.frame(t(as.matrix(df)))
header.true <- function(df) {
  names(df) <- as.character(unlist(df[1, ]))
  df[-1, ]
}
ds <- header.true(ds)


# ind = 1
# color <- list(c('green', 'red', 'blue'))

# # Histogram with density plot
# ggplot(df, aes(x=spm)) +
#   geom_histogram(aes(y=..density..), colour="white", fill=color[[1]][ind], alpha = 0.3)+
#   geom_density(alpha=.2, fill=color[[1]][ind], color = color[[1]][ind]) + ylab('Density')

# ggplot(data = ds, aes(
#   x = row.names(ds),
#   y = as.numeric(as.character(Delhi)),
#   group = 1
# )) + geom_point(color = 'green') + geom_line(linetype = "dashed", color = 'green') + 
#   ylab ('RMSE Error') + xlab('Imputation Methods')

ggplot() + 
  geom_line(data = ds, aes(x = row.names(ds), y = as.numeric(as.character(Delhi)), group = 1), color = "green", lwd=1.2, linetype='dashed') +
  geom_line(data = ds, aes(x = row.names(ds), y = as.numeric(as.character(Haryana)), group = 1), color = "red", lwd=1.2, linetype='dashed') +
  geom_line(data = ds, aes(x = row.names(ds), y = as.numeric(as.character(`West Bengal`)), group = 1), color = "blue", lwd=1.2, linetype='dashed') +
  
  geom_point(data = ds, aes(x = row.names(ds), y = as.numeric(as.character(Delhi)), group = 1), color = "green", size = 3) +
  geom_point(data = ds, aes(x = row.names(ds), y = as.numeric(as.character(Haryana)), group = 1), color = "red", size = 3) +
  geom_point(data = ds, aes(x = row.names(ds), y = as.numeric(as.character(`West Bengal`)), group = 1), color = "blue", size = 3) +
  
  ylab ('Error') + 
  xlab('Imputation Methods') +
  ggtitle("Graph of NRMSE Error") +
  theme(plot.title = element_text(hjust = 0.5))
  





